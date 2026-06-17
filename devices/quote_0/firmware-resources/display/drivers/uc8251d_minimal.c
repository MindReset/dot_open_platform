/**
 * @file uc8251d_minimal.c
 * @brief Minimal UC8251D e-paper display driver implementation.
 * @license Apache-2.0
 *
 * Scope:
 * - Uses ESP-IDF SPI master and GPIO APIs to drive UC8251D.
 * - Implements the fixed 152x296 monochrome full-refresh path with only the
 *   code needed for public bring-up and porting.
 */

/* SPDX-License-Identifier: Apache-2.0 */

#include "uc8251d_minimal.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "driver/gpio.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define UC8251D_BORDER_WHITE_REG  0x97
#define UC8251D_BUSY_TIMEOUT_MS   5000
#define UC8251D_BUSY_POLL_MS      10
#define UC8251D_RESET_DELAY_MS    10
#define UC8251D_SLEEP_DELAY_MS    2700
#define UC8251D_LUT_SIZE          376

static uc8251d_config_t s_cfg;
static spi_device_handle_t s_spi;
static bool s_inited;

static const uint8_t s_lut_gc[UC8251D_LUT_SIZE] = {
    /* VCOM */
    0x05, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00, 0x0E, 0x0E, 0x01, 0x0E, 0x0E, 0x0E,
    0x01, 0x00, 0x18, 0x18, 0x01, 0x0E, 0x0E, 0x01,
    0x01, 0x00, 0x23, 0x23, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    /* White to white */
    0x05, 0x90, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x40, 0x0E, 0x0E, 0x01, 0x0E, 0x0E, 0x0E,
    0x01, 0x90, 0x18, 0x18, 0x01, 0x0E, 0x0E, 0x01,
    0x01, 0x80, 0x23, 0x23, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    /* Black to white */
    0x05, 0x90, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x40, 0x0E, 0x0E, 0x01, 0x0E, 0x0E, 0x0E,
    0x01, 0x90, 0x18, 0x18, 0x01, 0x0E, 0x0E, 0x01,
    0x01, 0x80, 0x23, 0x23, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    /* White to black */
    0x05, 0x90, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x20, 0x0E, 0x0E, 0x01, 0x0E, 0x0E, 0x0E,
    0x01, 0x18, 0x18, 0x18, 0x01, 0x0E, 0x0E, 0x01,
    0x01, 0x10, 0x23, 0x23, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    /* Black to black */
    0x05, 0x90, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x20, 0x0E, 0x0E, 0x01, 0x0E, 0x0E, 0x0E,
    0x01, 0x18, 0x18, 0x18, 0x01, 0x0E, 0x0E, 0x01,
    0x01, 0x10, 0x23, 0x23, 0x01, 0x01, 0x01, 0x01,
};

static void delay_ms(uint32_t ms)
{
    vTaskDelay(pdMS_TO_TICKS(ms));
}

static esp_err_t write_byte(uint8_t value)
{
    spi_transaction_t trans = {
        .flags = SPI_TRANS_USE_TXDATA,
        .length = 8,
    };
    trans.tx_data[0] = value;
    return spi_device_polling_transmit(s_spi, &trans);
}

static esp_err_t write_data_bulk(const uint8_t *data, size_t len)
{
    while (len > 0) {
        size_t chunk = (len > 4096) ? 4096 : len;
        spi_transaction_t trans = {
            .length = chunk * 8,
            .tx_buffer = data,
        };
        esp_err_t ret = spi_device_polling_transmit(s_spi, &trans);
        if (ret != ESP_OK) {
            return ret;
        }
        data += chunk;
        len -= chunk;
    }
    return ESP_OK;
}

static esp_err_t cmd(uint8_t value)
{
    gpio_set_level((gpio_num_t)s_cfg.pin_dc, 0);
    return write_byte(value);
}

static esp_err_t data(uint8_t value)
{
    gpio_set_level((gpio_num_t)s_cfg.pin_dc, 1);
    return write_byte(value);
}

static esp_err_t data_bulk(const uint8_t *bytes, size_t len)
{
    gpio_set_level((gpio_num_t)s_cfg.pin_dc, 1);
    return write_data_bulk(bytes, len);
}

static void reset_panel(void)
{
    gpio_set_level((gpio_num_t)s_cfg.pin_reset, 1);
    delay_ms(UC8251D_RESET_DELAY_MS);
    gpio_set_level((gpio_num_t)s_cfg.pin_reset, 0);
    delay_ms(UC8251D_RESET_DELAY_MS);
    gpio_set_level((gpio_num_t)s_cfg.pin_reset, 1);
    delay_ms(UC8251D_RESET_DELAY_MS);
}

static esp_err_t wait_busy(void)
{
    int64_t start_ms = esp_timer_get_time() / 1000;

    while (gpio_get_level((gpio_num_t)s_cfg.pin_busy) == 0) {
        esp_err_t ret = cmd(0x71);
        if (ret != ESP_OK) {
            return ret;
        }
        delay_ms(UC8251D_BUSY_POLL_MS);
        if ((esp_timer_get_time() / 1000) - start_ms > UC8251D_BUSY_TIMEOUT_MS) {
            return ESP_ERR_TIMEOUT;
        }
    }

    return ESP_OK;
}

static esp_err_t load_lut(void)
{
    esp_err_t ret = cmd(0x20);
    if (ret != ESP_OK) return ret;
    ret = data_bulk(&s_lut_gc[0], 80);
    if (ret != ESP_OK) return ret;

    ret = cmd(0x21);
    if (ret != ESP_OK) return ret;
    ret = data_bulk(&s_lut_gc[80], 56);
    if (ret != ESP_OK) return ret;

    ret = cmd(0x22);
    if (ret != ESP_OK) return ret;
    ret = data_bulk(&s_lut_gc[136], 80);
    if (ret != ESP_OK) return ret;

    ret = cmd(0x23);
    if (ret != ESP_OK) return ret;
    ret = data_bulk(&s_lut_gc[216], 80);
    if (ret != ESP_OK) return ret;

    ret = cmd(0x24);
    if (ret != ESP_OK) return ret;
    return data_bulk(&s_lut_gc[296], 80);
}

static esp_err_t power_on_panel(void)
{
    esp_err_t ret = cmd(0x00);
    if (ret != ESP_OK) return ret;
    if ((ret = data(0xF3)) != ESP_OK) return ret;
    if ((ret = data(0x0E)) != ESP_OK) return ret;

    if ((ret = cmd(0x01)) != ESP_OK) return ret;
    if ((ret = data(0x03)) != ESP_OK) return ret;
    if ((ret = data(0x00)) != ESP_OK) return ret;
    if ((ret = data(0x3F)) != ESP_OK) return ret;
    if ((ret = data(0x3F)) != ESP_OK) return ret;
    if ((ret = data(0x03)) != ESP_OK) return ret;

    if ((ret = cmd(0x06)) != ESP_OK) return ret;
    if ((ret = data(0x17)) != ESP_OK) return ret;
    if ((ret = data(0x17)) != ESP_OK) return ret;
    if ((ret = data(0x17)) != ESP_OK) return ret;

    if ((ret = cmd(0x61)) != ESP_OK) return ret;
    if ((ret = data(UC8251D_WIDTH)) != ESP_OK) return ret;
    if ((ret = data(UC8251D_HEIGHT / 256)) != ESP_OK) return ret;
    if ((ret = data(UC8251D_HEIGHT % 256)) != ESP_OK) return ret;

    if ((ret = cmd(0x30)) != ESP_OK) return ret;
    if ((ret = data(0x1B)) != ESP_OK) return ret;

    if ((ret = cmd(0x60)) != ESP_OK) return ret;
    if ((ret = data(0x22)) != ESP_OK) return ret;

    if ((ret = cmd(0x82)) != ESP_OK) return ret;
    if ((ret = data(0x00)) != ESP_OK) return ret;

    if ((ret = cmd(0x03)) != ESP_OK) return ret;
    if ((ret = data(0x10)) != ESP_OK) return ret;

    if ((ret = cmd(0x50)) != ESP_OK) return ret;
    if ((ret = data(UC8251D_BORDER_WHITE_REG)) != ESP_OK) return ret;

    if ((ret = cmd(0x04)) != ESP_OK) return ret;
    delay_ms(100);
    return wait_busy();
}

static esp_err_t update_panel(void)
{
    esp_err_t ret = cmd(0x12);
    if (ret != ESP_OK) {
        return ret;
    }
    delay_ms(100);
    return wait_busy();
}

static esp_err_t write_filled_plane(uint8_t value)
{
    uint8_t fill[128];
    memset(fill, value, sizeof(fill));

    for (size_t written = 0; written < UC8251D_BUFFER_SIZE; written += sizeof(fill)) {
        size_t len = UC8251D_BUFFER_SIZE - written;
        if (len > sizeof(fill)) {
            len = sizeof(fill);
        }
        esp_err_t ret = data_bulk(fill, len);
        if (ret != ESP_OK) return ret;
    }
    return ESP_OK;
}

static esp_err_t write_frame(uint8_t old_value, const uint8_t *new_frame)
{
    esp_err_t ret = load_lut();
    if (ret != ESP_OK) return ret;

    ret = cmd(0x10);
    if (ret != ESP_OK) return ret;
    ret = write_filled_plane(old_value);
    if (ret != ESP_OK) return ret;

    ret = cmd(0x13);
    if (ret != ESP_OK) return ret;
    return data_bulk(new_frame, UC8251D_BUFFER_SIZE);
}

static esp_err_t write_clear_frame(uint8_t new_value)
{
    esp_err_t ret = load_lut();
    if (ret != ESP_OK) return ret;

    ret = cmd(0x10);
    if (ret != ESP_OK) return ret;
    ret = write_filled_plane(0xFF);
    if (ret != ESP_OK) return ret;

    ret = cmd(0x13);
    if (ret != ESP_OK) return ret;
    return write_filled_plane(new_value);
}

esp_err_t uc8251d_init(const uc8251d_config_t *config)
{
    if (!config) {
        return ESP_ERR_INVALID_ARG;
    }
    if (s_inited) {
        return ESP_OK;
    }

    s_cfg = *config;
    if (s_cfg.spi_clock_hz <= 0) {
        s_cfg.spi_clock_hz = 15 * 1000 * 1000;
    }

    gpio_config_t out_conf = {
        .pin_bit_mask = (1ULL << s_cfg.pin_vin) |
                        (1ULL << s_cfg.pin_reset) |
                        (1ULL << s_cfg.pin_cs) |
                        (1ULL << s_cfg.pin_dc),
        .mode = GPIO_MODE_OUTPUT,
    };
    esp_err_t ret = gpio_config(&out_conf);
    if (ret != ESP_OK) return ret;

    gpio_config_t busy_conf = {
        .pin_bit_mask = (1ULL << s_cfg.pin_busy),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    ret = gpio_config(&busy_conf);
    if (ret != ESP_OK) return ret;

    gpio_set_level((gpio_num_t)s_cfg.pin_vin, 1);
    gpio_set_level((gpio_num_t)s_cfg.pin_cs, 1);
    gpio_set_level((gpio_num_t)s_cfg.pin_reset, 1);
    gpio_set_level((gpio_num_t)s_cfg.pin_dc, 1);
    delay_ms(10);

    spi_bus_config_t bus_cfg = {
        .mosi_io_num = s_cfg.pin_mosi,
        .miso_io_num = -1,
        .sclk_io_num = s_cfg.pin_sck,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4096,
    };
    ret = spi_bus_initialize(s_cfg.spi_host, &bus_cfg, SPI_DMA_CH_AUTO);
    if (ret != ESP_OK && ret != ESP_ERR_INVALID_STATE) return ret;

    spi_device_interface_config_t dev_cfg = {
        .clock_speed_hz = s_cfg.spi_clock_hz,
        .mode = 0,
        .spics_io_num = s_cfg.pin_cs,
        .queue_size = 1,
    };
    ret = spi_bus_add_device(s_cfg.spi_host, &dev_cfg, &s_spi);
    if (ret != ESP_OK) return ret;

    reset_panel();
    ret = wait_busy();
    if (ret != ESP_OK) return ret;

    ret = power_on_panel();
    if (ret == ESP_OK) {
        s_inited = true;
    }
    return ret;
}

esp_err_t uc8251d_display(const uint8_t *data)
{
    if (!data) {
        return ESP_ERR_INVALID_ARG;
    }
    if (!s_inited) {
        return ESP_ERR_INVALID_STATE;
    }

    gpio_set_level((gpio_num_t)s_cfg.pin_vin, 1);
    reset_panel();
    esp_err_t ret = wait_busy();
    if (ret != ESP_OK) return ret;
    ret = power_on_panel();
    if (ret != ESP_OK) return ret;

    ret = write_frame(0xFF, data);
    if (ret != ESP_OK) return ret;
    return update_panel();
}

esp_err_t uc8251d_clear(bool white)
{
    if (!s_inited) {
        return ESP_ERR_INVALID_STATE;
    }

    gpio_set_level((gpio_num_t)s_cfg.pin_vin, 1);
    reset_panel();
    esp_err_t ret = wait_busy();
    if (ret != ESP_OK) return ret;
    ret = power_on_panel();
    if (ret != ESP_OK) return ret;

    ret = write_clear_frame(white ? 0xFF : 0x00);
    if (ret != ESP_OK) return ret;
    return update_panel();
}

esp_err_t uc8251d_sleep(void)
{
    if (!s_inited) {
        return ESP_ERR_INVALID_STATE;
    }

    esp_err_t ret = wait_busy();
    if (ret != ESP_OK) return ret;

    delay_ms(UC8251D_SLEEP_DELAY_MS);
    if ((ret = cmd(0x07)) != ESP_OK) return ret;
    if ((ret = data(0xA5)) != ESP_OK) return ret;

    gpio_set_direction((gpio_num_t)s_cfg.pin_vin, GPIO_MODE_INPUT);
    return ESP_OK;
}

/* SPDX-License-Identifier: Apache-2.0 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "driver/spi_master.h"
#include "esp_err.h"
#include "uc8251d_minimal.h"

static const uc8251d_config_t display_config = {
    .spi_host = SPI2_HOST,
    .pin_vin = 20,
    .pin_busy = 3,
    .pin_reset = 4,
    .pin_dc = 5,
    .pin_cs = 6,
    .pin_sck = 10,
    .pin_mosi = 7,
    .spi_clock_hz = 15 * 1000 * 1000,
};

static void draw_border(uint8_t *frame)
{
    memset(frame, 0xFF, UC8251D_BUFFER_SIZE);

    for (int y = 0; y < UC8251D_HEIGHT; y++) {
        for (int x = 0; x < UC8251D_WIDTH; x++) {
            bool border = (x < 4) ||
                          (x >= UC8251D_WIDTH - 4) ||
                          (y < 4) ||
                          (y >= UC8251D_HEIGHT - 4);
            if (!border) {
                continue;
            }

            int pixel_index = y * UC8251D_WIDTH + x;
            frame[pixel_index / 8] &= (uint8_t)~(1U << (7 - (pixel_index % 8)));
        }
    }
}

void app_main(void)
{
    static uint8_t frame[UC8251D_BUFFER_SIZE];

    ESP_ERROR_CHECK(uc8251d_init(&display_config));
    ESP_ERROR_CHECK(uc8251d_clear(true));

    draw_border(frame);
    ESP_ERROR_CHECK(uc8251d_display(frame));
    ESP_ERROR_CHECK(uc8251d_sleep());
}

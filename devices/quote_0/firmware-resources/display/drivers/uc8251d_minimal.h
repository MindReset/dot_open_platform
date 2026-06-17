/**
 * @file uc8251d_minimal.h
 * @brief Minimal UC8251D e-paper display driver interface.
 * @license Apache-2.0
 *
 * Scope:
 * - Targets ESP-IDF and a 152x296 monochrome UC8251D e-paper panel.
 * - Provides only initialization, full-frame display, clear, and sleep helpers
 *   so the code remains easy to inspect and port.
 */

/* SPDX-License-Identifier: Apache-2.0 */

#ifndef UC8251D_MINIMAL_H
#define UC8251D_MINIMAL_H

#include <stdbool.h>
#include <stdint.h>
#include "driver/spi_master.h"
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UC8251D_WIDTH        152
#define UC8251D_HEIGHT       296
#define UC8251D_BUFFER_SIZE  ((UC8251D_WIDTH * UC8251D_HEIGHT) / 8)

typedef struct {
    spi_host_device_t spi_host;
    int pin_vin;
    int pin_busy;
    int pin_reset;
    int pin_dc;
    int pin_cs;
    int pin_sck;
    int pin_mosi;
    int spi_clock_hz;
} uc8251d_config_t;

/**
 * @brief Initialize the UC8251D panel and SPI bus.
 */
esp_err_t uc8251d_init(const uc8251d_config_t *config);

/**
 * @brief Display one 1bpp full-screen frame.
 *
 * @note data must contain UC8251D_BUFFER_SIZE bytes. Each bit maps to one
 * pixel, where 1 means white and 0 means black.
 */
esp_err_t uc8251d_display(const uint8_t *data);

/**
 * @brief Clear the display.
 *
 * @param white true for white, false for black.
 */
esp_err_t uc8251d_clear(bool white);

/**
 * @brief Enter sleep and release the display power control pin.
 */
esp_err_t uc8251d_sleep(void);

#ifdef __cplusplus
}
#endif

#endif /* UC8251D_MINIMAL_H */

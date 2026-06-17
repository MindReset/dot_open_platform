/**
 * @file uc8151_minimal.h
 * @brief Minimal UC8151/IL0324 e-paper display driver interface.
 * @license Apache-2.0
 *
 * Scope:
 * - Targets ESP-IDF and the 152x296 monochrome UC8151/IL0324 e-paper panel
 *   used by the Quote/0 Early Bird Edition.
 * - Provides only initialization, full-frame display, clear, and sleep helpers
 *   so the code remains easy to inspect and port.
 */

/* SPDX-License-Identifier: Apache-2.0 */

#ifndef UC8151_MINIMAL_H
#define UC8151_MINIMAL_H

#include <stdbool.h>
#include <stdint.h>
#include "driver/spi_master.h"
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UC8151_WIDTH        152
#define UC8151_HEIGHT       296
#define UC8151_BUFFER_SIZE  ((UC8151_WIDTH * UC8151_HEIGHT) / 8)

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
} uc8151_config_t;

/**
 * @brief Initialize the UC8151 panel and SPI bus.
 */
esp_err_t uc8151_init(const uc8151_config_t *config);

/**
 * @brief Display one 1bpp full-screen frame.
 *
 * @note data must contain UC8151_BUFFER_SIZE bytes. Each bit maps to one
 * pixel, where 1 means white and 0 means black.
 */
esp_err_t uc8151_display(const uint8_t *data);

/**
 * @brief Clear the display.
 *
 * @param white true for white, false for black.
 */
esp_err_t uc8151_clear(bool white);

/**
 * @brief Enter sleep and release the display power control pin.
 */
esp_err_t uc8151_sleep(void);

#ifdef __cplusplus
}
#endif

#endif /* UC8151_MINIMAL_H */

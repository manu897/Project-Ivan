// This file contains the driver code for the ST7789V2 display, including functions for initializing the display, sending data, and controlling display settings.

#include "st7789v2_driver.h"
#include "driver/spi_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Define the SPI bus and display parameters
#define SPI_HOST    HSPI_HOST
#define SPI_DMA_CH  1
#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 240

static spi_device_handle_t spi;

// Function to initialize the ST7789V2 display
esp_err_t st7789v2_init() {
    esp_err_t ret;

    // Initialize the SPI bus
    spi_bus_config_t buscfg = {
        .miso_io_num = -1,
        .mosi_io_num = GPIO_NUM_23, // Set your MOSI pin
        .sclk_io_num = GPIO_NUM_18, // Set your SCLK pin
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = DISPLAY_WIDTH * DISPLAY_HEIGHT * 2 + 8
    };
    ret = spi_bus_initialize(SPI_HOST, &buscfg, SPI_DMA_CH);
    if (ret != ESP_OK) {
        return ret;
    }

    // Configure the display device
    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = SPI_MASTER_FREQ_40M,
        .mode = 0,
        .spics_io_num = GPIO_NUM_5, // Set your CS pin
        .queue_size = 1,
        .flags = SPI_DEVICE_NO_DUMMY
    };
    ret = spi_bus_add_device(SPI_HOST, &devcfg, &spi);
    if (ret != ESP_OK) {
        return ret;
    }

    // Initialize the display
    // Send initialization commands to the display
    // (Refer to the ST7789V2 datasheet for command sequences)
    // ...

    return ESP_OK;
}

// Function to send data to the display
esp_err_t st7789v2_send_data(const uint8_t *data, size_t length) {
    spi_transaction_t trans = {
        .length = length * 8,
        .tx_buffer = data
    };
    return spi_device_transmit(spi, &trans);
}

// Function to set the display window
esp_err_t st7789v2_set_window(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
    // Set the column address
    uint8_t col_cmds[4] = {
        0x2A, // Column Address Set
        (x >> 8) & 0xFF, // X start
        x & 0xFF, // X end
        ((x + width - 1) >> 8) & 0xFF, // X end
        (x + width - 1) & 0xFF
    };
    st7789v2_send_data(col_cmds, sizeof(col_cmds));

    // Set the row address
    uint8_t row_cmds[4] = {
        0x2B, // Row Address Set
        (y >> 8) & 0xFF, // Y start
        y & 0xFF, // Y end
        ((y + height - 1) >> 8) & 0xFF, // Y end
        (y + height - 1) & 0xFF
    };
    st7789v2_send_data(row_cmds, sizeof(row_cmds));

    // Write to RAM
    uint8_t ram_cmd = 0x2C; // Memory Write
    st7789v2_send_data(&ram_cmd, 1);

    return ESP_OK;
}

// Function to clear the display
void st7789v2_clear(uint16_t color) {
    uint16_t data[DISPLAY_WIDTH * DISPLAY_HEIGHT];
    for (int i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT; i++) {
        data[i] = color;
    }
    st7789v2_set_window(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    st7789v2_send_data((uint8_t *)data, sizeof(data));
}
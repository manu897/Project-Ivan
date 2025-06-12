#include <stdio.h>
#include "lvgl.h"
#include "st7789v2_driver.h"
#include "qmi8658_driver.h"

void app_main(void) {
    // Initialize the LVGL graphics library
    lv_init();

    // Initialize the display driver
    st7789v2_init();

    // Initialize the IMU sensor
    qmi8658_init();

    // Main loop for rendering the HUD
    while (1) {
        // Handle LVGL tasks
        lv_task_handler();

        // Delay to control the loop speed
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
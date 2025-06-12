#include "lvgl.h"
#include "st7789v2_driver.h"

void lvgl_init(void) {
    // Initialize LVGL
    lv_init();

    // Initialize the display driver
    st7789v2_init();

    // Set up the display buffer
    static lv_color_t buf1[LV_HOR_RES_MAX * LV_VER_RES_MAX]; // Buffer for the display
    static lv_disp_buf_t disp_buf; // Display buffer structure
    lv_disp_buf_init(&disp_buf, buf1, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX);

    // Create a display driver
    lv_disp_drv_t disp_drv; // Display driver structure
    lv_disp_drv_init(&disp_drv); // Initialize the display driver
    disp_drv.buffer = &disp_buf; // Assign the buffer to the display driver
    disp_drv.flush_cb = st7789v2_flush; // Set the flush callback function
    lv_disp_drv_register(&disp_drv); // Register the display driver
}

void lvgl_task(void *pvParameter) {
    while (1) {
        // Handle LVGL tasks
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(10)); // Delay for a short period
    }
}
# CMakeLists.txt

cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "Project-Ivan")
project(${PROJECT_NAME})

# Include the ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Specify the main application source files
set(MAIN_SRC "main/app_main.c")

# Add components
set(COMPONENTS "lvgl" "display" "imu")

# Register the main application
idf_component_register(SRCS ${MAIN_SRC}
                       INCLUDE_DIRS "."
                       REQUIRES ${COMPONENTS})
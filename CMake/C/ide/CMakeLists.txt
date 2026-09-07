cmake_minimum_required(VERSION 3.20)

project(zapp
    VERSION 1.0.0
    LANGUAGES C
)

# ============================================================
# C Standard
# ============================================================

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


# ============================================================
# Project paths
# ============================================================

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(APP_DIR      ${PROJECT_ROOT}/app)
set(MID_DIR      ${PROJECT_ROOT}/mid)
set(DRIVER_DIR   ${PROJECT_ROOT}/driver)


# ============================================================
# DRIVER
# ============================================================

file(GLOB DRIVER_SOURCES
    ${DRIVER_DIR}/src/*.c
)

add_library(driver STATIC
    ${DRIVER_SOURCES}
)

target_include_directories(driver
    PUBLIC
        ${DRIVER_DIR}/inc
)


# ============================================================
# MIDDLEWARE
# ============================================================

file(GLOB MID_SOURCES
    ${MID_DIR}/cli/*.c
    ${MID_DIR}/logger/*.c
)

add_library(mid STATIC
    ${MID_SOURCES}
)

target_include_directories(mid
    PUBLIC
        ${MID_DIR}/cli
        ${MID_DIR}/logger
)

target_link_libraries(mid
    PUBLIC
        driver
)


# ============================================================
# APPLICATION
# ============================================================

add_executable(zapp
    ${APP_DIR}/main.c
    ${APP_DIR}/zapp/zapp.c
)

target_include_directories(zapp
    PRIVATE
        ${APP_DIR}
        ${APP_DIR}/zapp
)

target_link_libraries(zapp
    PRIVATE
        mid
)


# ============================================================
# Build information
# ============================================================

message(STATUS "========================================")
message(STATUS " Project : ${PROJECT_NAME}")
message(STATUS " Version : ${PROJECT_VERSION}")
message(STATUS " Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "========================================")
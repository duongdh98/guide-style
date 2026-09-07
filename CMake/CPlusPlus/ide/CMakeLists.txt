
cmake_minimum_required(VERSION 3.20)

project(zapp
    VERSION 1.0.0
    LANGUAGES CXX
)

# ============================================================
# C++ Standard
# ============================================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# ============================================================
# Project Paths
# ============================================================

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(APP_DIR      ${PROJECT_ROOT}/app)
set(MID_DIR      ${PROJECT_ROOT}/mid)
set(DRIVER_DIR   ${PROJECT_ROOT}/driver)


# ============================================================
# DRIVER
# ============================================================

file(GLOB DRIVER_SOURCES
    ${DRIVER_DIR}/src/*.cpp
)

add_library(driver STATIC
    ${DRIVER_SOURCES}
)

target_include_directories(driver
    PUBLIC
        ${DRIVER_DIR}/inc
)


# ============================================================
# MID
# ============================================================

file(GLOB MID_SOURCES
    ${MID_DIR}/cli/*.cpp
    ${MID_DIR}/logger/*.cpp
    ${MID_DIR}/delay/*.cpp
)

add_library(mid STATIC
    ${MID_SOURCES}
)

target_include_directories(mid
    PUBLIC
        ${MID_DIR}/cli
        ${MID_DIR}/logger
        ${MID_DIR}/delay
)

target_link_libraries(mid
    PUBLIC
        driver
)


# ============================================================
# APP
# ============================================================

add_executable(zapp
    ${APP_DIR}/main.cpp
    ${APP_DIR}/zapp/zapp.cpp
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
# Information
# ============================================================

message(STATUS "========================================")
message(STATUS " Project : ${PROJECT_NAME}")
message(STATUS " Version : ${PROJECT_VERSION}")
message(STATUS " Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "========================================")

cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if (VERSION VERSION_GREATER_EQUAL 3.1)
    add_compile_options(-std=c++11 -fsanitize=address -g)
else()
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
endif()

find_package(
    Qt5 REQUIRED
    Core
    Network
)

set(
    DRIVERS_GTEST_SRC
    regtronicdriver_test.cpp
)

set(
    DRIVERS_GMOCK_H
    mockipressureregulator.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}..
    ${CMAKE_CURRENT_SOURCE_DIR}drivers
    ${CMAKE_CURRENT_SOURCE_DIR}drivers/gtest
    ${CURRENT_SOURCE_DIR}../
    ${CURRENT_SOURCE_DIR}../drivers
    ${CURRENT_SOURCE_DIR}../drivers/gtest
    ${CMAKE_CURRENT_SOURCE_DIR}peripheral
    ${CMAKE_CURRENT_SOURCE_DIR}peripheral/gtest
    ${CURRENT_SOURCE_DIR}../peripheral
    ${CURRENT_SOURCE_DIR}../peripheral/gtest
    ${CMAKE_CURRENT_SOURCE_DIR}lib
    ${CMAKE_CURRENT_SOURCE_DIR}lib/gtest
    ${CURRENT_SOURCE_DIR}../lib
    ${CURRENT_SOURCE_DIR}../lib/gtest
)

add_library(
    drivers_gtest
    ${DRIVERS_GTEST_SRC}
    ${DRIVERS_GMOCK_H}
)

target_link_libraries(
    drivers_gtest
    drivers
    lib_gtest
    lib
    peripheral_gtest
    peripheral
    gtest_main
    gmock
    Qt5::Core
    Qt5::Network
)

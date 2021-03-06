cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if (VERSION VERSION_GREATER_EQUAL 3.1)
    add_compile_options(-std=c++11)
else()
    set(CMAKE_CXX_STANDARD 11)
endif()

find_package(
    Qt5 REQUIRED
    Core
    Network
    Widgets
)

set(
    UI_GTEST_SRC
    isettingswidget_test.cpp
    settingstextfield_test.cpp
    networkaddressfield_test.cpp
    settingsform_test.cpp

    pressurepanel_test.cpp
)

set(
    UI_GMOCK_H
    mocksettingswidget.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}..
    ${CMAKE_CURRENT_SOURCE_DIR}drivers
    ${CMAKE_CURRENT_SOURCE_DIR}drivers/gtest
    ${CMAKE_CURRENT_SOURCE_DIR}peripheral
    ${CMAKE_CURRENT_SOURCE_DIR}peripheral/gtest
    ${CURRENT_SOURCE_DIR}../
    ${CURRENT_SOURCE_DIR}../drivers
    ${CURRENT_SOURCE_DIR}../drivers/gtest
    ${CURRENT_SOURCE_DIR}../peripheral
    ${CURRENT_SOURCE_DIR}../peripheral/gtest
)

add_library(
    ui_gtest
    ${UI_GTEST_SRC}
    ${UI_GMOCK_H}
)

target_compile_options(
    ui_gtest
    PRIVATE
        -fno-sanitize=address
)

target_link_libraries(
    ui_gtest
    ui
    drivers_gtest
    drivers
    peripheral_gtest
    peripheral
    gtest_main
    gmock
    Qt5::Core
    Qt5::Network
    Qt5::Widgets
)

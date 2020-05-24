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
    PERIPHERAL_GTEST_SRC
    #regtronicdriver_test.cpp
    qstorage_test.cpp
)

set(
    PERIPHERAL_GMOCK_H
    mockdatalink.h
    #mockipressureregulator.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_SOURCE_DIR}/gtest
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}..
    ${CMAKE_CURRENT_SOURCE_DIR}drivers
    ${CMAKE_CURRENT_SOURCE_DIR}drivers/gtest
    ${CURRENT_SOURCE_DIR}../
    ${CURRENT_SOURCE_DIR}../drivers
    ${CURRENT_SOURCE_DIR}../drivers/gtest
    #${CMAKE_CURRENT_SOURCE_DIR}lib
    #${CMAKE_CURRENT_SOURCE_DIR}lib/gtest
    #${CURRENT_SOURCE_DIR}../lib
    #${CURRENT_SOURCE_DIR}../lib/gtest
)

add_library(
    peripheral_gtest
    ${PERIPHERAL_GTEST_SRC}
    ${PERIPHERAL_GMOCK_H}
)

target_link_libraries(
    peripheral_gtest
    peripheral
    #lib_gtest
    #lib
    gtest_main
    gmock
    Qt5::Core
    Qt5::Network
)

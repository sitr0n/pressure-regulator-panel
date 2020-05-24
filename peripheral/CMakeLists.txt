add_subdirectory(gtest)
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
)

set(
    PERIPHERAL_SRC
    comlinedevice.cpp
)

set(
    PERIPHERAL_H
    qstorage.h

    comlinedevice.h
)

include_directories(
    ${CURRENT_SOURCE_DIR}/../
    ${CURRENT_SOURCE_DIR}/../lib
    ${CURRENT_SOURCE_DIR}/../lib/gtest
)


qt5_wrap_cpp(PERIPHERAL_QT_HEADERS_MOC ${PERIPHERAL_H})

add_library(
    peripheral
    ${PERIPHERAL_SRC}
    ${PERIPHERAL_QT_HEADERS_MOC}
)

target_link_libraries(
    peripheral
    lib
    Qt5::Core
    Qt5::Network
)

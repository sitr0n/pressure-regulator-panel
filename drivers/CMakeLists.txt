add_subdirectory(gtest)
cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if (VERSION VERSION_GREATER_EQUAL 3.1)
    set(CMAKE_CXX_STANDARD 11)
else()
    add_compile_options(-std=c++11)
endif()

find_package(
    Qt5 REQUIRED
    Core
    Network
)

set(
    DRIVERS_SRC
    comlinedevice.cpp
    regtronic_driver.cpp
)

set(
    DRIVERS_H
    externaldevice.h
    ipressureregulator.h

    comlinedevice.h
    regtronic_driver.h
)

qt5_wrap_cpp(DRIVERS_QT_HEADERS_MOC ${DRIVERS_H})

add_library(
    drivers
    ${DRIVERS_SRC}
    ${DRIVERS_QT_HEADERS_MOC}
)

target_link_libraries(
    drivers
    Qt5::Core
    Qt5::Network
)

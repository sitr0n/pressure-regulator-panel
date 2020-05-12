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
)

set(
    LIB_GTEST_SRC
    presentationmodel_test.cpp
)

set(
    LIB_GMOCK_H
)

include_directories(
    ${CURRENT_SOURCE_DIR}../
    ${CMAKE_SOURCE_DIR}/gtest
)

add_library(
    lib_gtest
    ${LIB_GTEST_SRC}
    ${LIB_GMOCK_H}
)

target_link_libraries(
    lib_gtest
    lib
    gtest_main
    gmock
    Qt5::Core
)

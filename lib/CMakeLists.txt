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
)

set(
    LIB_SRC
    presentationmodel.cpp
)

set(
    LIB_H
    presentationmodel.h
)

qt5_wrap_cpp(LIB_QT_HEADERS_MOC ${LIB_H})

add_library(
    lib
    ${LIB_SRC}
    ${LIB_QT_HEADERS_MOC}
)

target_link_libraries(
    lib
    Qt5::Core
)

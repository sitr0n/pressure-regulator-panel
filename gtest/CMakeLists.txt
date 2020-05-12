add_subdirectory(gtest)
cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if (VERSION VERSION_GREATER_EQUAL 3.1)
    add_compile_options(-std=c++11)
    add_compile_options(-fsanitize=thread)
    # Qt/QPushButton creates a memory leak when one sets its button text
    # However, it is a convenient widget to have and you really don't need those kbytes anyway
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        add_compile_options(-fno-sanitize=address,leak)
    else()
        add_compile_options(-fsanitize-blacklist=sanitizer_blacklist.txt)
    endif()
else()
    set(CMAKE_CXX_STANDARD 11)
    set(MAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-sanitize=address,leak")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize-blacklist=sanitizer_blacklist.txt")
    endif()
endif()

find_package(
    Qt5 REQUIRED
    Core
    Widgets
)

set(TEST_PROGRAM pressure-regulator-panel_test)
set(TEST_SRC main_test.cpp)

include_directories(
    ./gtest
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../drivers
    ${CMAKE_CURRENT_SOURCE_DIR}/../drivers/gtest
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest
    ${CMAKE_CURRENT_SOURCE_DIR}/../ui
    ${CMAKE_CURRENT_SOURCE_DIR}/../ui/gtest
)

add_executable(
    ${TEST_PROGRAM}
    ${TEST_SRC}
)

target_link_libraries(
    ${TEST_PROGRAM}
    gtest_main
    gmock
    drivers
    drivers_gtest
    lib
    lib_gtest
    ui
    ui_gtest
    Qt5::Core
    Qt5::Widgets
)

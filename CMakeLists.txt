cmake_minimum_required(VERSION 3.20)
project(advent_of_code_2021)

set(CMAKE_CXX_STANDARD 20)

add_executable(advent_of_code "")

target_sources(advent_of_code
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/adv_1.h
    )

target_include_directories(advent_of_code
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
    )

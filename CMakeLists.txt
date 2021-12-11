cmake_minimum_required(VERSION 3.20)
project(advent_of_code_2021)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS=ON)

add_executable(advent_of_code "")

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/ sources)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/include/ headers)

target_sources(advent_of_code
    PRIVATE
        ${sources}
    PUBLIC
        ${headers}
    )

target_include_directories(advent_of_code
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
    )

target_precompile_headers(advent_of_code
    PUBLIC
       ${CMAKE_CURRENT_LIST_DIR}/include/pch.h
    )

cmake_minimum_required(VERSION 3.20)
project(advent_of_code_2021)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS=ON)

add_executable(advent_of_code "")


target_sources(advent_of_code
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/helper_functions.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/adv_1.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/adv_2.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/adv_3.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/adv_4.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/adv_5.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/adv_6.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/adv_7.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/advent_of_code.h
    ${CMAKE_CURRENT_LIST_DIR}/include/helper_functions.h
    ${CMAKE_CURRENT_LIST_DIR}/include/adv_1.h
    ${CMAKE_CURRENT_LIST_DIR}/include/adv_2.h
    ${CMAKE_CURRENT_LIST_DIR}/include/adv_3.h
    ${CMAKE_CURRENT_LIST_DIR}/include/adv_4.h
    ${CMAKE_CURRENT_LIST_DIR}/include/adv_5.h
    ${CMAKE_CURRENT_LIST_DIR}/include/adv_6.h
    ${CMAKE_CURRENT_LIST_DIR}/include/adv_7.h
    )

target_include_directories(advent_of_code
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
    )

target_precompile_headers(advent_of_code
    PUBLIC
       ${CMAKE_CURRENT_LIST_DIR}/include/pch.h
    )

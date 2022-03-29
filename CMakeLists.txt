cmake_minimum_required(VERSION 3.20)

project(forth_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include("cmake/CPM.cmake")

CPMAddPackage(
    NAME fmt
    GITHUB_REPOSITORY fmtlib/fmt
    GIT_TAG 8.1.1
)

CPMAddPackage(
    NAME magic_enum
    GITHUB_REPOSITORY Neargye/magic_enum
    GIT_TAG v0.7.3
)

add_subdirectory(forth)
add_subdirectory(forthc)

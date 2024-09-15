cmake_minimum_required(VERSION 3.15...3.30)

project(KTU-microprocessor VERSION 1.0
    DESCRIPTION "??"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(Compiler)

add_subdirectory(src)
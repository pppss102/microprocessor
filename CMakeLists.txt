cmake_minimum_required(VERSION 3.15...3.30)

project(KTU-microprocessor VERSION 1.0
  DESCRIPTION "??"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(Compiler)

file(GLOB MAIN_CPP_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HPP_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.h)

target_sources(Compiler PUBLIC ${MAIN_CPP_FILES} ${MAIN_HPP_FILES})

# list(FILTER MAIN_CPP_FILES EXCLUDE REGEX ${PROJECT_SOURCE_DIR}/src/main.cpp)
list(REMOVE_ITEM MAIN_CPP_FILES "${PROJECT_SOURCE_DIR}/src/main.cpp")
file(GLOB TEST_CPP_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/tests/*.cpp)
file(GLOB TEST_HPP_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/tests/*.h)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Tests)
target_sources(Tests PUBLIC ${MAIN_CPP_FILES} ${MAIN_HPP_FILES} ${TEST_CPP_FILES} ${TEST_HPP_FILES})
target_link_libraries(
  Tests
  GTest::gtest_main
  GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(Tests)
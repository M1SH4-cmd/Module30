cmake_minimum_required(VERSION 3.25)
project(Task2 VERSION 1.1)

set(CMAKE_CXX_STANDARD 23)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG dec9422db3af470641f8b0d90e4b451c4daebf64)
FetchContent_MakeAvailable(cpr)

add_executable(Task2 main.cpp)
target_link_libraries(Task2 PRIVATE cpr::cpr)
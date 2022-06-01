cmake_minimum_required(VERSION 3.14.0)
project(leet VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/scripts/cmake)

enable_testing()

add_subdirectory(src)

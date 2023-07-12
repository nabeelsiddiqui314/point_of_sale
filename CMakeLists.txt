cmake_minimum_required(VERSION 3.16)

project(POS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

find_package(Python 3.11 COMPONENTS Interpreter Development REQUIRED)
add_subdirectory(vendor/pybind11)

add_subdirectory(src/Application)
add_subdirectory(src/Core)

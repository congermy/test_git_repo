cmake_minimum_required(VERSION 3.21)
project(regenerate)

set(CMAKE_CXX_STANDARD 14)

find_package(Python3 3.10 COMPONENTS Interpreter Development)

add_executable(regenerate main.cpp)

if (Python3_FOUND)
    message("Python include directory: " ${Python3_INCLUDE_DIRS})
    message("Python version is: " ${Python3_VERSION})
    message("Python library is: " ${Python3_LIBRARIES})
    include_directories(${Python3_INCLUDE_DIRS})
    target_link_libraries(regenerate ${Python3_LIBRARIES})
endif (Python3_FOUND)
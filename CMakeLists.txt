cmake_minimum_required(VERSION 3.10)
project(inputPlay3DS)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(inputPlay3DS
    src/main.cpp
    src/ControllerManager.cpp
    src/NetworkClient.cpp
)

target_link_libraries(inputPlay3DS ${SDL2_LIBRARIES})

cmake_minimum_required(VERSION 3.3)
project(modus_tollens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
    ${CMAKE_SOURCE_DIR}/game/world
    ${CMAKE_SOURCE_DIR}/game/world/fields
    ${CMAKE_SOURCE_DIR}/game/world/materials
)

set(SOURCE_FILES
    src/main.cpp
    src/game/world/Field.cpp
    src/game/world/World.cpp
    src/game/world/fields/Meadow.cpp
    src/game/world/fields/Water.cpp
    src/game/world/materials/Soil.cpp
)

add_executable(modus_tollens ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.3)
project(modus_tollens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(INCLUDES
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/game/
    ${CMAKE_SOURCE_DIR}/src/game/world
    ${CMAKE_SOURCE_DIR}/src/game/world/fields
    ${CMAKE_SOURCE_DIR}/src/game/world/materials
)

set(SOURCE_FILES
    src/main.cpp
    src/game/world/Field.cpp
    src/game/world/World.cpp
    src/game/world/fields/Meadow.cpp
    src/game/world/fields/Water.cpp
    src/game/world/materials/Soil.cpp
)

set(TEST_SOURCES
    test/GameData_test.cpp
)

include_directories(${INCLUDES})

add_executable(modus_tollens ${SOURCE_FILES})

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(modus_tollens_test ${TEST_SOURCES})
target_link_libraries(modus_tollens_test ${GTEST_BOTH_LIBRARIES})
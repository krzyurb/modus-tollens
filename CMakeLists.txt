cmake_minimum_required(VERSION 3.3)
project(modus_tollens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O2 -pthread")

find_package (Threads)
add_executable (main src/main.cpp)
target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT})

set(INCLUDES
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/game/
    ${CMAKE_SOURCE_DIR}/src/game/timing
    ${CMAKE_SOURCE_DIR}/src/game/rendering
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
    src/game/rendering/Renderer.cpp
    src/game/world/FieldFactory.cpp
    src/game/world/WorldGenerator.cpp
    src/game/world/WorldGenerator.h
    src/game/timing/GameTimer.cpp
    src/game/timing/Observable.cpp
    src/game/timing/Observable.cpp
    src/game/timing/Calendar.cpp
    src/game/timing/Calendar.h
    src/game/window/FieldSelector.cpp
    src/game/window/FieldsSelector.h
    src/game/window/Sidebar.cpp
    src/game/window/Sidebar.h)

set(TEST_SOURCES
    test/GameData_test.cpp
)

include_directories(${INCLUDES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIRS})

find_package (Threads)
add_executable(modus_tollens ${SOURCE_FILES})
target_link_libraries(modus_tollens ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

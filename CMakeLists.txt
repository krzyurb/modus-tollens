cmake_minimum_required(VERSION 3.3)
project(modus_tollens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic -O2 -pthread -lboost_system")

set(INCLUDES
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/game/
    ${CMAKE_SOURCE_DIR}/src/game/player
    ${CMAKE_SOURCE_DIR}/src/game/timing
    ${CMAKE_SOURCE_DIR}/src/game/rendering
    ${CMAKE_SOURCE_DIR}/src/game/rendering/map_modes
    ${CMAKE_SOURCE_DIR}/src/game/window
    ${CMAKE_SOURCE_DIR}/src/game/world
    ${CMAKE_SOURCE_DIR}/src/game/world/fields
    ${CMAKE_SOURCE_DIR}/src/game/world/materials
)

set(SOURCE_FILES
    src/main.cpp
    src/game/player/Player.cpp
    src/game/player/Stock.cpp
    src/game/world/Field.cpp
    src/game/world/World.cpp
    src/game/world/fields/Meadow.cpp
    src/game/world/fields/Water.cpp
    src/game/world/materials/Soil.cpp
    src/game/rendering/Renderer.cpp
    src/game/world/FieldFactory.cpp
    src/game/world/WorldGenerator.cpp
    src/game/timing/GameTimer.cpp
    src/game/timing/Observable.cpp
    src/game/timing/Observable.cpp
    src/game/timing/Calendar.cpp
    src/game/window/FieldSelector.cpp
    src/game/window/Sidebar.cpp
    src/game/window/Sidebar.h
    src/game/rendering/ResourceHolder.cpp
    src/game/world/fields/Forest.cpp
    src/game/world/fields/Forest.h
    src/game/world/materials/Tree.cpp
    src/game/world/materials/Tree.h
    src/game/window/Button.cpp
    src/game/window/Button.h
    src/game/window/ButtonListener.cpp
    src/game/window/ButtonListener.h
    src/game/window/ButtonHandler.cpp
    src/game/window/ButtonHandler.h
    src/game/window/listeners/BuildCity.cpp
    src/game/window/listeners/BuildCity.h
    src/game/world/fields/City.cpp
    src/game/ModusTollens.cpp
    src/game/player/Character.cpp
    src/game/rendering/map_modes/MapModeRenderer.h
    src/game/rendering/map_modes/FertilityMode.cpp
    src/game/rendering/map_modes/FertilityMode.h
    src/game/rendering/map_modes/TreesMode.cpp
    src/game/rendering/map_modes/TreesMode.h
    src/game/world/Building.cpp
    src/game/world/Building.h
    src/game/world/buildings/Sawmill.cpp
    src/game/world/buildings/Sawmill.h
    src/game/world/buildings/Farm.cpp
    src/game/world/buildings/Farm.h src/game/window/listeners/NewBuilding.cpp src/game/window/listeners/NewBuilding.h)
set(TEST_SOURCES
    test/GameData_test.cpp
)

include_directories(${INCLUDES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIRS})

find_package (Threads)
find_package( Boost 1.60 COMPONENTS filesystem REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

add_executable(modus_tollens ${SOURCE_FILES})
target_link_libraries(modus_tollens ${SFML_LIBRARIES} ${Boost_LIBRARIES})

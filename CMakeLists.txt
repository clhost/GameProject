cmake_minimum_required(VERSION 3.6)
project(GameProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game/Game.cpp Game/Game.h Game/Map/Map.cpp Game/Map/Map.h Game/Pacman/Charachter.cpp Game/Pacman/Charachter.h Draw/Animation.cpp Draw/Animation.h Other/Direction.h Game/Ghosts/Enemy.cpp Game/Ghosts/Enemy.h Other/Point.h Algorithms/WaveTracingAlgorithm.cpp Algorithms/WaveTracingAlgorithm.h Game/Ghosts/Blinky.cpp Game/Ghosts/Blinky.h Game/Ghosts/Pinky.cpp Game/Ghosts/Pinky.h Game/Ghosts/Inkey.cpp Game/Ghosts/Inkey.h Game/Ghosts/Clyde.cpp Game/Ghosts/Clyde.h Game/Ghosts/GhostFactory.cpp Game/Ghosts/GhostFactory.h)
set(EXECUTABLE_NAME "GameProject")
add_executable(GameProject ${SOURCE_FILES})

set(SFML_DIR "/home/geek/ClionProjects/GameProject/SFML-2.4.0/share/SFML/cmake/Modules")
set(CMAKE_MODULE_PATH "/home/geek/ClionProjects/GameProject/SFML-2.4.0/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
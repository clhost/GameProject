cmake_minimum_required(VERSION 3.6)
project(GameProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp Game.h Map.cpp Map.h Charachter.cpp Charachter.h Animation.cpp Animation.h Direction.h Enemy.cpp Enemy.h Point.h Menu/Menu.cpp Menu/Menu.h)
set(EXECUTABLE_NAME "GameProject")
add_executable(GameProject ${SOURCE_FILES})

set(SFML_DIR "/home/geek/ClionProjects/GameProject/SFML-2.4.0/share/SFML/cmake/Modules")
set(CMAKE_MODULE_PATH "/home/geek/ClionProjects/GameProject/SFML-2.4.0/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
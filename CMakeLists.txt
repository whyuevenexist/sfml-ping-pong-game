cmake_minimum_required(VERSION 3.28)
project(Pong CXX)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_library(objects 
    STATIC 
      src/Ball/Ball.cpp
      src/Player/Player.cpp 
      src/AssetManager/AssetManager.cpp
      src/Game/Game.cpp)

target_include_directories(objects PUBLIC src)

target_link_libraries(objects PRIVATE SFML::Graphics SFML::Window SFML::System)

add_executable(Pong main.cpp)

target_link_libraries(Pong PUBLIC objects)
cmake_minimum_required(VERSION 3.16)
project(NoliEngineV3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 CONFIG REQUIRED)

add_executable(NoliEngineV3
    main.cpp
    Core/Game.cpp
    Core/Scene.cpp
    Core/GameObject.cpp
)

target_link_libraries(NoliEngineV3 PRIVATE SDL2::SDL2)

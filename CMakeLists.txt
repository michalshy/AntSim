cmake_minimum_required(VERSION 3.30)
project(AntSimulator)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(AntSimulator src/main.cpp
        src/Simulation/Entities/Ant.hpp
        src/Simulation/Entities/Ant.cpp
        src/Graphics/MainWindow.hpp
        src/Graphics/MainWindow.cpp
        src/Engine.hpp
        src/Engine.cpp
        src/Graphics/Textures/TextureManager.hpp
        src/Graphics/Textures/TextureManager.cpp
        src/Simulation/Anthill.hpp
        src/Simulation/Anthill.cpp
        src/Logic/Timer.hpp
        src/Logic/Timer.cpp
        src/Graphics/MainWindow.cpp
        src/Graphics/Views/UiView.hpp
        src/Graphics/Views/UiView.cpp
        src/Graphics/Views/AntView.hpp
        src/Graphics/Views/AntView.cpp
        src/Globals.hpp
        src/Logic/Managers/InputManager.hpp
        src/Logic/Managers/InputManager.cpp
        src/Simulation/Environment/Wall.hpp
        src/Simulation/Environment/Walls.hpp
        src/Simulation/Environment/Wall.cpp
        src/Simulation/Environment/Walls.cpp
)

target_link_libraries(AntSimulator PRIVATE sfml-graphics)

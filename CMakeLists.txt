cmake_minimum_required(VERSION 3.27)
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
        src/Graphics/Textures/AntTexture.hpp
        src/Graphics/Textures/AntTexture.cpp
)

target_link_libraries(AntSimulator PRIVATE sfml-graphics)

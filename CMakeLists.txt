cmake_minimum_required(VERSION 3.30)
project(AntSimulator)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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

enable_testing()

add_executable(
  Tests
  testing/mainTests.cc
)

target_link_libraries(
        Tests
        PRIVATE sfml-graphics
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)


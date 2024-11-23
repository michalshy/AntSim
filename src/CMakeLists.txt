set(lib_files 
        Simulation/Entities/Ant.hpp
        Simulation/Entities/Ant.cpp
        Graphics/MainWindow.hpp
        Graphics/MainWindow.cpp
        Engine.hpp
        Engine.cpp
        Graphics/Textures/TextureManager.hpp
        Graphics/Textures/TextureManager.cpp
        Simulation/Anthill.hpp
        Simulation/Anthill.cpp
        Logic/Timer.hpp
        Logic/Timer.cpp
        Graphics/MainWindow.cpp
        Graphics/Views/UiView.hpp
        Graphics/Views/UiView.cpp
        Graphics/Views/AntView.hpp
        Graphics/Views/AntView.cpp
        Globals.hpp
        Logic/Managers/InputManager.hpp
        Logic/Managers/InputManager.cpp
        Simulation/Environment/Wall.hpp
        Simulation/Environment/Walls.hpp
        Simulation/Environment/Wall.cpp
        Simulation/Environment/Walls.cpp
)

add_library(ant_simulator_lib
        ${lib_files}
)

add_executable(ant_simulator 
        main.cpp
)

target_link_libraries(ant_simulator_lib 
    sfml-graphics
    sfml-system
    sfml-main
    sfml-audio
    sfml-network
    sfml-window
)

target_link_libraries(ant_simulator
ant_simulator_lib
)


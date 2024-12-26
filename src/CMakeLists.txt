set(lib_files 
        Simulation/Entities/Ant.hpp
        Simulation/Entities/Ant.cpp
        Graphics/Window.hpp
        Graphics/Window.cpp
        Engine.hpp
        Engine.cpp
        Graphics/Textures/TextureManager.hpp
        Graphics/Textures/TextureManager.cpp
        Simulation/Anthill.hpp
        Simulation/Anthill.cpp
        Logic/Timer.hpp
        Logic/Timer.cpp
        Graphics/Views/UiView.hpp
        Graphics/Views/UiView.cpp
        Graphics/Views/AntView.hpp
        Graphics/Views/AntView.cpp
        Globals.hpp
        Logic/Managers/InputManager.hpp
        Logic/Managers/InputManager.cpp
        Simulation/Environment/Objects/Wall.hpp
        Simulation/Environment/Environment.hpp
        Simulation/Environment/Objects/Wall.cpp
        Simulation/Environment/Environment.cpp
        Common/Markers/Marker.hpp
        Common/Random/Random.hpp        
        Common/Shapes/Shapes.hpp  
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


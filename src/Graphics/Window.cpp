//
// Created by Michin on 20.06.2024.
//

#include "Window.hpp"

Window::Window(std::shared_ptr<sf::Texture> _backgroundTex)
{
    window.create({ WindowParams::WIDTH, WindowParams::HEIGHT }, "AntSimulator");
    window.setFramerateLimit(144);
    ant_view = AntView();
    dragging = false;
    mouse_pos = sf::Mouse::getPosition();

    //Background section
    f_bounds = sf::FloatRect(-25000.f, -15000.f, 50000.f, 30000.f);
    i_bounds = sf::IntRect(f_bounds);
    background = sf::Sprite((* _backgroundTex), i_bounds);
    background.setPosition(f_bounds.left, f_bounds.top - 1000.f + ant_view.ReturnView().getSize().y);
    view_offset_y = 0;
    sprite_offset_y = 0;
    texture_height = _backgroundTex->getSize().y;

    //UiView
    ui_view = UiView();
}

void Window::Draw(Anthill & ants){
        GetWindow().clear(sf::Color(150, 75, 0, 255));

        GetWindow().setView(ant_view.ReturnView());
        window.draw(background);
        for(Ant& ant : ants.GetAnts())
        {
            ant.DrawAnt(GetWindow());
        }

        GetWindow().setView(ui_view.ReturnView());
        //DRAWING UI HERE

        GetWindow().display();
}

bool Window::SetActive(bool state) {
    return window.setActive(state);
}

void Window::ProcessEvents() {
    for (auto event = sf::Event{}; window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if(event.type == sf::Event::Resized)
        {
            AdjustOnResize();
        }
        if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.delta > 0)
                ZoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, (1.f / 1.3));
            else if (event.mouseWheelScroll.delta < 0)
                ZoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, 1.3);
        }
        if(dragging)
        {
            if(event.type == sf::Event::MouseMoved)
            {
                MoveRelativeToMouse();
            }
        }
        
    }
}

void Window::SetViewOnAnts() {
    window.setView(ant_view.ReturnView()); 
}

void Window::ZoomViewAt(sf::Vector2i pixel, float zoom)
{
	const sf::Vector2f before_coord{ window.mapPixelToCoords(pixel) };
	ant_view.ReturnView().zoom(zoom);
	const sf::Vector2f after_coord{ window.mapPixelToCoords(pixel) };
	const sf::Vector2f offset_coords{ before_coord - after_coord };
	ant_view.ReturnView().move(offset_coords);
	window.setView(ant_view.ReturnView());
}

void Window::MoveRelativeToMouse()
{
    sf::Vector2i nextPos = sf::Mouse::getPosition();
    const sf::Vector2f offset_coords{ mouse_pos - nextPos };
    ant_view.ReturnView().move(offset_coords);
    window.setView(ant_view.ReturnView());
}

void Window::AdjustOnResize()
{
    float ratio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
    ant_view.ReturnView().setSize(WindowParams::HEIGHT * ratio, WindowParams::HEIGHT);
}

void Window::SetMousePos(sf::Vector2i mouse_pos_proc)
{
    mouse_pos = mouse_pos_proc;
}

void Window::SetDragging(bool state)
{
    dragging = state;
}

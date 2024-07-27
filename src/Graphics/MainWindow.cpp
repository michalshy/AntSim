//
// Created by Michin on 20.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow()
{
    window.setFramerateLimit(144);
    antV = AntView();
    dragging = false;
    mousePos = sf::Mouse::getPosition();
}

void MainWindow::Draw(Anthill & ants){
        GetWindow().clear(sf::Color::Cyan);
        for(Ant& ant : ants.GetAnts())
        {
            ant.DrawAnt(this->GetWindow());
        }
        GetWindow().display();
}

bool MainWindow::SetActive(bool state) {
    return window.setActive(state);
}

void MainWindow::ProcessEvents() {
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

void MainWindow::SetViewOnAnts() {
    window.setView(antV.ReturnView());
}

void MainWindow::InputManaging() {
        if(sf::Mouse::isButtonPressed((sf::Mouse::Middle)))
        {
            mousePos = sf::Mouse::getPosition();
            dragging = true;
        }
        else
        {
            dragging = false;
        }
}

void MainWindow :: ZoomViewAt(sf::Vector2i pixel, float zoom)
{
	const sf::Vector2f beforeCoord{ window.mapPixelToCoords(pixel) };
	antV.ReturnView().zoom(zoom);
	const sf::Vector2f afterCoord{ window.mapPixelToCoords(pixel) };
	const sf::Vector2f offsetCoords{ beforeCoord - afterCoord };
	antV.ReturnView().move(offsetCoords);
	window.setView(antV.ReturnView());
}

void MainWindow::MoveRelativeToMouse()
{
    sf::Vector2i nextPos = sf::Mouse::getPosition();
    const sf::Vector2f offsetCoords{ nextPos - mousePos };
    antV.ReturnView().move(offsetCoords);
    window.setView(antV.ReturnView());
}

void MainWindow::AdjustOnResize()
{
    float ratio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
}






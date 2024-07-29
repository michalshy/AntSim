//
// Created by Michin on 20.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow(sf::Texture * _backgroundTex)
{
    window.setFramerateLimit(144);
    antV = AntView();
    dragging = false;
    mousePos = sf::Mouse::getPosition();

    //Background section
    fBounds = sf::FloatRect(-25000.f, -15000.f, 50000.f, 30000.f);
    iBounds = sf::IntRect(fBounds);
    background = sf::Sprite((* _backgroundTex), iBounds);
    background.setPosition(fBounds.left, fBounds.top - 1000.f + antV.ReturnView().getSize().y);
    viewOffsetY = 0;
    spriteOffsetY = 0;
    textureHeight = _backgroundTex->getSize().y;
}

void MainWindow::Draw(Anthill & ants){
        GetWindow().clear(sf::Color(150, 75, 0, 255));
        window.draw(background);
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
    const sf::Vector2f offsetCoords{ mousePos - nextPos };
    antV.ReturnView().move(offsetCoords);
    window.setView(antV.ReturnView());
}

void MainWindow::AdjustOnResize()
{
    float ratio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
    antV.ReturnView().setSize(WindowParams::HEIGHT * ratio, WindowParams::HEIGHT);
}

void MainWindow::SetMousePos(sf::Vector2i mousePosProc)
{
    mousePos = mousePosProc;
}

void MainWindow::SetDragging(bool state)
{
    dragging = state;
}

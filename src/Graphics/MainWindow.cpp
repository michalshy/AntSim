//
// Created by Michin on 20.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow()
{
    window.setFramerateLimit(144);
    antV = AntView();
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
        }
        if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.delta > 0)
                ZoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, (1.f / 1.3));
            else if (event.mouseWheelScroll.delta < 0)
                ZoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, 1.3);
        }
    }
}

void MainWindow::SetViewOnAnts() {
    window.setView(antV.ReturnView());
}

void MainWindow::MoveRelativeToMouse() {
    
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






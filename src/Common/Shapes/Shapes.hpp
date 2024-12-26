#include "SFML/Graphics.hpp"
#include "../../Simulation/Entities/Ant.hpp"

namespace AntShapes{
    struct Radar {
        sf::ConvexShape left;
        sf::ConvexShape right;
        sf::ConvexShape mid;

        Radar() {
            left.setPointCount(5);
            left.setFillColor(sf::Color(255,255,255,20));
            left.setPoint(0, sf::Vector2f(0, 0));
            left.setPoint(1, sf::Vector2f(20, 0));
            left.setPoint(2, sf::Vector2f(40, -20));
            left.setPoint(3, sf::Vector2f(20, -40));
            left.setPoint(4, sf::Vector2f(0, -40));
            left.setOrigin(20, 20);

            right.setPointCount(5);
            right.setFillColor(sf::Color(255,255,255,20));
            right.setPoint(0, sf::Vector2f(0, 0));
            right.setPoint(1, sf::Vector2f(-20, 0));
            right.setPoint(2, sf::Vector2f(-40, -20));
            right.setPoint(3, sf::Vector2f(-20, -40));
            right.setPoint(4, sf::Vector2f(0, -40));
            right.setOrigin(-20, 20);

            mid.setPointCount(5);
            mid.setFillColor(sf::Color(255,255,255,20));
            mid.setPoint(0, sf::Vector2f(0, 0));
            mid.setPoint(1, sf::Vector2f(20, 0));
            mid.setPoint(2, sf::Vector2f(20, -20));
            mid.setPoint(3, sf::Vector2f(0, -20));
            mid.setOrigin(10, 10);
        }

        Radar(sf::Vector2f pos) {
            left.setPointCount(4);
            left.setOrigin(pos);
            left.setFillColor(sf::Color(255,0,0,100));
            left.setPoint(0, sf::Vector2f(pos.x - 5, pos.y));
            left.setPoint(1, sf::Vector2f(pos.x - 20, pos.y + 5));
            left.setPoint(2, sf::Vector2f(pos.x - 20, pos.y - 15));
            left.setPoint(3, sf::Vector2f(pos.x - 5,  pos.y - 20));

            mid.setPointCount(4);
            mid.setOrigin(pos);
            mid.setFillColor(sf::Color(0,255,0,100));
            mid.setPoint(0, sf::Vector2f(pos.x - 5,  pos.y - 20));
            mid.setPoint(1, sf::Vector2f(pos.x + 5,  pos.y - 20));
            mid.setPoint(2, sf::Vector2f(pos.x + 5,  pos.y));
            mid.setPoint(3, sf::Vector2f(pos.x - 5,  pos.y));

            right.setPointCount(4);
            right.setOrigin(pos);
            right.setFillColor(sf::Color(0,0,255,100));
            right.setPoint(0, sf::Vector2f(pos.x + 5, pos.y));
            right.setPoint(1, sf::Vector2f(pos.x + 20, pos.y + 5));
            right.setPoint(2, sf::Vector2f(pos.x + 20, pos.y - 15));
            right.setPoint(3, sf::Vector2f(pos.x + 5,  pos.y - 20));
        }

        void Draw(sf::RenderWindow & window) {
            window.draw(left);
            window.draw(right);
            window.draw(mid);
        }

        void Move(sf::Vector2f vel) {
            left.move(vel);
            right.move(vel);
            mid.move(vel);
        }

        void Rotate(float angle) {
            left.rotate(angle);
            right.rotate(angle);
            mid.rotate(angle);
        }

        void SetRotation(float angle) {
            left.setRotation(angle);
            right.setRotation(angle);
            mid.setRotation(angle);
        }
    };
}
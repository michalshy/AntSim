#ifndef __MARKER_HPP__
#define __MARKER_HPP__

#include "SFML/Graphics.hpp"

template <class Shape, class Color, class Float>
concept drawable = requires(Shape shape, Color color, Float pos_x, Float pos_y)
{
    {color} -> std::convertible_to<sf::Color>;
    {shape.setFillColor(color)} -> std::convertible_to<void>;
    {shape.getFillColor()} -> std::convertible_to<const sf::Color&>;
    {shape.setPosition(pos_x, pos_y)};
};

template<class Shape, class Color = sf::Color, class Float = float>
requires drawable<Shape, Color, Float>
class Marker {
    Shape entity;
    u8 strength;
    u64 weight;
    bool dead;
public:
    Marker(const Shape& _entity, s64 _x_pos, s64 _y_pos, u8 _strength, u64 _weight)
    {
        entity = _entity;
        entity.setPosition(_x_pos, _y_pos);
        weight = _weight;
        strength = _strength;
        dead = false;
    }
    void draw(sf::RenderWindow & window){
        window.draw(entity);
    }
    void update()
    {
        sf::Color tmp = entity.getFillColor();
        entity.setFillColor(sf::Color(tmp.r, tmp.g, tmp.b, static_cast<u8>(strength)));
        strength -= 1;
        if(strength == 0)
            dead = true;
    }
    bool is_dead(){ return dead; }
    u64 get_weight(){ return weight; }
    const Shape& get(){ return entity; }
};


#endif //__MARKER_HPP__
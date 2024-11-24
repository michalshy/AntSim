#ifndef __MARKER_HPP__
#define __MARKER_HPP__

#include "SFML/Graphics.hpp"

template <class Shape, class Index>
concept drawable = requires(Shape shape, Index index)
{
    {shape.getPointCount()} -> std::convertible_to<std::size_t>;
    {index} -> std::convertible_to<size_t>;
    {shape.getPoint(index)} -> std::convertible_to<sf::Vector2f>;
};

template<class Shape, class Index = size_t>
requires drawable<Shape, Index>
class Marker {
    Shape entity;
    s64 x_pos;
    s64 y_pos;
    u64 strength;
    u64 weight;
public:
    Marker(const Shape& _entity, s64 _x_pos, s64 _y_pos)
    {
        entity = _entity;
        x_pos = _x_pos;
        y_pos = _y_pos;
    }
    void draw(sf::RenderWindow & window){
        window.draw(entity);
    }
    u64 get_strength(){ return strength; }
    u64 get_weight(){ return weight; }
    const Shape& get(){ return entity; }
    std::pair<s64, s64> get_position() { return {x_pos, y_pos}; }
};


#endif //__MARKER_HPP__
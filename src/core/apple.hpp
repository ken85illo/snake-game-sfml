#pragma once

#include <SFML/Graphics.hpp>

class Apple : public sf::CircleShape {
public:
    Apple();
    void draw();
    void update();

private:
    const float m_radius;
};

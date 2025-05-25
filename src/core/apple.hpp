#pragma once

#include <SFML/Graphics.hpp>

class Apple : public sf::CircleShape {
private:
    const float m_radius;

public:
    Apple();
    void draw();
    void update();
};

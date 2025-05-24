#pragma once

#include <SFML/Graphics.hpp>

namespace game {

class Apple : public sf::CircleShape {
private:
    const float m_radius;

public:
    Apple();
    void draw();
    void update();
};
} // namespace game

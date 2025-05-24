#pragma once

#include <SFML/Graphics.hpp>

namespace game {

class Snake {
private:
    std::vector<sf::CircleShape> m_snake;
    sf::CircleShape m_bodyPart{};
    sf::Clock m_clock{};

    const float m_radius;
    const uint m_initialSize = 4;
    const uint m_movesPerSecond = 10;

    // Move upwards initially
    float m_verticalMove = -1.f;
    float m_horizontalMove = 0.f;


public:
    Snake();
    void draw();
    void move();
    void update();
};
} // namespace game

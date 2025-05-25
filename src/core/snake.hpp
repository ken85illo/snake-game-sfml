#pragma once

#include <SFML/Graphics.hpp>

class Snake {
private:
    std::vector<sf::CircleShape> m_snake;
    sf::CircleShape m_bodyPart{};
    sf::Clock m_clock{};

    const float m_radius;
    const uint m_initialSize = 4;
    const uint m_movesPerSecond = 10;
    const uint16_t delayVal = 3000;

    bool delay = true; // Have delay at the start

    // Move upwards initially
    float m_verticalMove = -1.f;
    float m_horizontalMove = 0.f;


public:
    Snake();
    void draw();
    void move();
    void update();
};

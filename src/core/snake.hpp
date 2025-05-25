#pragma once

#include <SFML/Graphics.hpp>

class Snake {
public:
    Snake();
    void draw();
    void move();
    void update();

private:
    std::vector<sf::RectangleShape> m_snake;
    sf::RectangleShape m_bodyPart{};
    sf::Clock m_clock{};

    const uint m_initialSize = 4;
    const uint m_movesPerSecond = 10;
    const uint16_t delayVal = 3000;

    bool delay = true; // Have delay at the start

    // Move upwards initially
    float m_verticalMove = -1.f;
    float m_horizontalMove = 0.f;
};

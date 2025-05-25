#include "apple.hpp"
#include <engine.hpp>

Apple::Apple() : sf::CircleShape(), m_radius(window->gridSize.x / 2.f) {
    srand(time(0));
    this->setFillColor(sf::Color::Red);
    this->setRadius(m_radius);

    this->update();
}

void Apple::draw() {
    window->draw(*this);
}

void Apple::update() {
    const uint col = rand() % window->numOfGrid;
    const uint row = rand() % window->numOfGrid;
    this->setPosition({ m_radius * 2 * col, m_radius * 2 * row });
}

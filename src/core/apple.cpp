#include "apple.hpp"
#include "engine.hpp"

game::Apple::Apple() : sf::CircleShape(), m_radius(gridSize.x / 2.f) {
    srand(time(0));
    this->setFillColor(sf::Color::Red);
    this->setRadius(m_radius);

    this->update();
}

void game::Apple::draw() {
    window.draw(*this);
}

void game::Apple::update() {
    const uint col = rand() % numOfGrid;
    const uint row = rand() % numOfGrid;
    this->setPosition({ m_radius * 2 * col, m_radius * 2 * row });
}

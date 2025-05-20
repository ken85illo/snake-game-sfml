#include <core/apple.hpp>
#include <core/engine.hpp>

game::Apple::Apple()
: sf::CircleShape(), m_radius(game::gridSize.x / 2.f), m_numOfGrid(game::numOfGrid) {
    srand(time(0));
    this->setFillColor(sf::Color::Red);
    this->setRadius(m_radius);

    this->update();
}

void game::Apple::draw() {
    game::window->draw(*this);
}

void game::Apple::update() {
    const int col = rand() % m_numOfGrid;
    const int row = rand() % m_numOfGrid;

    this->setPosition({ m_radius * 2 * col, m_radius * 2 * row });
}

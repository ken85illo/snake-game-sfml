#pragma once

#include <SFML/Graphics.hpp>

namespace game {
class Window : public sf::RenderWindow {
private:
    static constexpr unsigned int m_style = sf::Style::Close;
    static constexpr sf::State m_state = sf::State::Windowed;
    static constexpr unsigned int m_framerateLimit = 30u;
    unsigned int m_numOfGrid = 0;
    sf::RectangleShape gridRect;

    void update(const std::optional<sf::Event> event);
    void render();

    void drawGrid();

public:
    Window(unsigned int width, unsigned int height, sf::String title, unsigned int numOfGrid = 0);
    void gameLoop();
};
}; // namespace game

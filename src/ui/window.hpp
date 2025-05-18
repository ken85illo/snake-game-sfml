#pragma once

#include "menu.hpp"
#include <SFML/Graphics.hpp>

namespace game {
class Window : private sf::RenderWindow {
private:
    static constexpr uint m_style{ sf::Style::Close };
    static constexpr sf::State m_state{ sf::State::Windowed };
    static constexpr uint m_framerateLimit{ 30u };

    bool m_showGrid;
    uint m_numOfGrid;
    sf::RectangleShape m_gridRect;
    game::Menu mainMenu{ this };

    void m_update(const std::optional<sf::Event>& event);
    void m_render();
    void m_drawGrid();

public:
    Window(uint width, uint height, sf::String title, bool showGrid = false, uint numOfGrid = 25);
    void gameLoop();
};
} // namespace game

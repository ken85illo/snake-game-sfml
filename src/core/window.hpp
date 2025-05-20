#pragma once

#include <SFML/Graphics.hpp>

namespace game {

class Menu;
class Apple;

class Window : public sf::RenderWindow {
private:
    static constexpr uint m_style{ sf::Style::Close };
    static constexpr sf::State m_state{ sf::State::Windowed };
    static constexpr uint m_framerateLimit{ 30u };

    bool m_showGrid;
    sf::RectangleShape m_gridRect;
    game::Menu* m_mainMenu;
    game::Apple* m_apple;

    void m_update();
    void m_render();
    void m_drawGrid();

public:
    Window(uint width, uint height, sf::String title, bool showGrid = false, uint numOfGrid = 25);
    ~Window();
    void gameLoop();
};

} // namespace game

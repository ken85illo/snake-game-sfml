#pragma once

#include <SFML/Graphics.hpp>

namespace game {

class Menu;
class Apple;
class Snake;

class Window : public sf::RenderWindow {
private:
    static constexpr uint m_style{ sf::Style::Close };
    static constexpr sf::State m_state{ sf::State::Windowed };
    static constexpr uint m_framerateLimit{ 30u };

    bool m_showGrid;
    sf::RectangleShape m_gridRect;
    Menu* m_mainMenu;
    Snake* m_snake;

    void update();
    void render();
    void drawGrid();

public:
    Window(uint width, uint height, sf::String title, uint numOfGrid = 25, bool showGrid = false);
    ~Window();
    void gameLoop();
};

} // namespace game

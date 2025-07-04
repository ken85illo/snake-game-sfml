#pragma once

#include <SFML/Graphics.hpp>

#include <core/apple.hpp>
#include <core/snake.hpp>
#include <ui/menu.hpp>

class Window : public sf::RenderWindow {
public:
    enum State {
        MENU_STATE,
        PLAY_STATE,
    };

    State state = MENU_STATE;
    uint numOfGrid;
    sf::Vector2f gridSize;
    std::optional<sf::Event> event;
    Apple* apple;
    uint8_t score = 0;

    Window(uint width, uint height, sf::String title, uint numOfGrid = 25, bool showGrid = false);
    ~Window();
    void gameLoop();

private:
    static constexpr uint m_style{ sf::Style::Close };
    static constexpr sf::State m_state{ sf::State::Windowed };
    static constexpr uint m_framerateLimit{ 30u };

    bool m_showGrid;
    sf::RectangleShape m_gridRect;
    Menu* m_mainMenu;
    Snake* m_snake;

    const sf::Font m_scoreFont{ "res/arial.ttf" };
    sf::Text m_scoreText = sf::Text(m_scoreFont, "Score: 0", 15);

    void update();
    void scoreUpdate();
    void render();
    void drawGrid();
};

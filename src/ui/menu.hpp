#pragma once

#include <SFML/Graphics.hpp>

namespace game {

class Button;
enum ButtonFunction : int;

class Menu {
private:
    static constexpr uint m_titleTextSize = 100;
    static constexpr uint m_buttonTextSize = 50;

    const sf::Font m_titleFont{ "res/arial.ttf" };
    sf::Text m_titleText{ m_titleFont, "SNAKE GAME" };

    const sf::Vector2f m_startButtonSize{ 200, 70 };
    const sf::String m_startText{ "PLAY" };
    game::Button* m_startButton;

    const sf::Vector2f m_quitButtonSize = { 200, 70 };
    const sf::String m_quitText{ "QUIT" };
    game::Button* m_quitButton;

    const sf::Text m_sfmlText = sf::Text(m_titleFont, "Made with SFML", 15);

    void initTitleText(float yPos);
    void initButtonText(game::Button* const button, float yPos, sf::Vector2f size);

public:
    Menu();
    ~Menu();
    void draw();
    void update();
};
} // namespace game

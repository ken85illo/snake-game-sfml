#pragma once

#include <SFML/Graphics.hpp>

#include "button.hpp"

class Menu {
private:
    static constexpr uint m_titleTextSize = 100;
    static constexpr uint m_buttonTextSize = 50;

    const sf::Font m_titleFont{ "res/arial.ttf" };
    sf::Text m_titleText{ m_titleFont, "SNAKE GAME" };

    const sf::Vector2f m_startButtonSize{ 200, 70 };
    const sf::String m_startText{ "PLAY" };
    Button m_startButton{ Button::PLAY, "PLAY", m_buttonTextSize };

    const sf::Vector2f m_quitButtonSize = { 200, 70 };
    const sf::String m_quitText{ "QUIT" };
    Button m_quitButton{ Button::QUIT, "QUIT", m_buttonTextSize };

    const sf::Text m_sfmlText = sf::Text(m_titleFont, "Made with SFML", 15);

    void initTitleText(float yPos);
    void initButtonText(Button& button, float yPos, sf::Vector2f size);

public:
    Menu();
    void draw();
    void update();
};

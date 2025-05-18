#pragma once

#include "button.hpp"

namespace game {
class Menu {
private:
    sf::RenderWindow* m_window;

    static constexpr uint m_titleTextSize = 80;
    static constexpr uint m_buttonTextSize = 50;

    const sf::Font m_titleFont{ "res/arial.ttf" };
    sf::Text m_titleText{ m_titleFont, "SNAKE GAME" };

    const sf::Vector2f m_startButtonSize{ 200, 70 };
    const sf::String m_startText{ "PLAY" };
    game::Button m_startButton{ m_startText, m_buttonTextSize };

    const sf::Vector2f m_quitButtonSize = { 200, 70 };
    const sf::String m_quitText{ "QUIT" };
    game::Button m_quitButton{ m_quitText, m_buttonTextSize };

    const sf::Text m_sfmlText = sf::Text(m_titleFont, "Made with SFML", 15);

    void m_initTitleText();
    void m_initButtonText(game::Button& button, float yPos, sf::Vector2f size);

public:
    Menu(sf::RenderWindow* window);
    void draw();
    void update(const std::optional<sf::Event>& event);
};
} // namespace game

#pragma once

#include <SFML/Graphics.hpp>

namespace game {

enum ButtonFunction : int {
    PLAY,
    QUIT,
};

class Button {
private:
    ButtonFunction m_function;
    const float m_textOffsetX = 0.f;
    const float m_textOffsetY = 0.f;

    const sf::Font m_font{ "res/arial.ttf" };
    sf::RectangleShape m_buttonRect{};
    sf::Text m_buttonText{ m_font };
    sf::Clock clock;
    void m_buttonLogic();

public:
    Button(ButtonFunction function,
    sf::String text,
    uint charSize,
    sf::Vector2f offset = { 0.f, 0.f });

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f pos);

    sf::Vector2f getSize() const;
    void draw();
    void update();
};

static const sf::Color s_default{ 0xFFFFFFFF };
static const sf::Color s_hovered{ 0xAAAAAAFF };
static const sf::Color s_clicked{ 0x00FF00FF };
} // namespace game

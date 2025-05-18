#pragma once

#include <SFML/Graphics.hpp>

namespace game {
class Button {
private:
    const float m_textOffsetX = 0.f;
    const float m_textOffsetY = 0.f;

    const sf::Font m_font{ "res/arial.ttf" };
    sf::RectangleShape m_buttonRect{};
    sf::Text m_buttonText{ m_font };
    sf::Clock clock;

public:
    Button(sf::String text, uint charSize, sf::Vector2f offset = { 0.f, 0.f });

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f pos);

    sf::Vector2f getSize() const;
    void draw(sf::RenderWindow* window);
    void update(const std::optional<sf::Event>& event, const sf::RenderWindow* window);
};
} // namespace game

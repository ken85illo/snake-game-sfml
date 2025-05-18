#include "button.hpp"
#include <SFML/Window/Mouse.hpp>

game::Button::Button(sf::String text, uint charSize, sf::Vector2f offset)
: m_textOffsetX(offset.x), m_textOffsetY(offset.y) {
    clock.reset();

    m_buttonText.setString(text);
    m_buttonText.setFont(m_font);
    m_buttonText.setCharacterSize(charSize);
    m_buttonText.setFillColor(sf::Color::White);
    m_buttonText.setOutlineColor(sf::Color::Black);
    m_buttonText.setOutlineThickness(1);
    m_buttonText.setOrigin(m_buttonText.getLocalBounds().getCenter());

    m_buttonRect.setFillColor(sf::Color::White);
}

void game::Button::setSize(sf::Vector2f size) {
    m_buttonRect.setSize(size);
    m_buttonRect.setOrigin(m_buttonRect.getLocalBounds().getCenter());
}

void game::Button::setPosition(sf::Vector2f pos) {
    m_buttonRect.setPosition(pos);
    m_buttonText.setPosition({ pos.x + m_textOffsetX, pos.y + m_textOffsetY });
}

sf::Vector2f game::Button::getSize() const {
    return m_buttonRect.getSize();
}

void game::Button::draw(sf::RenderWindow* window) {
    window->draw(m_buttonRect);
    window->draw(m_buttonText);
}

static const sf::Color s_default(0xFFFFFFFF);
static const sf::Color s_hovered(0xAAAAAAFF);

void game::Button::update(const std::optional<sf::Event>& event,
const sf::RenderWindow* window) {

    // Button hover effect
    if(!clock.isRunning()) {
        m_buttonRect.getGlobalBounds().contains(
        (sf::Vector2f)sf::Mouse::getPosition(*window)) ?
        m_buttonRect.setFillColor(s_hovered) :
        m_buttonRect.setFillColor(s_default);
    }

    auto buttonPressed = [&event, this]() {
        const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>();
        if(mousePressed) {
            bool intersects = m_buttonRect.getGlobalBounds().contains(
            (sf::Vector2f)mousePressed->position);
            bool clickedLeft = mousePressed->button == sf::Mouse::Button::Left;

            return intersects && clickedLeft;
        }
        return false;
    };

    // Button turns green when pressed
    if(buttonPressed()) {
        clock.start();
        m_buttonRect.setFillColor(sf::Color::Green);
    }

    // Reset the color after clicking
    if(clock.isRunning() && clock.getElapsedTime().asMilliseconds() >= 100) {
        m_buttonRect.setFillColor(s_hovered);
        clock.reset();
    }
}

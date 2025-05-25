#include "button.hpp"
#include <engine.hpp>

Button::Button(Function function, sf::String text, uint charSize, sf::Vector2f offset)
: m_textOffsetX(offset.x), m_textOffsetY(offset.y), m_function(function) {
    m_clock.reset();

    m_buttonText.setString(text);
    m_buttonText.setFont(m_font);
    m_buttonText.setCharacterSize(charSize);
    m_buttonText.setFillColor(sf::Color::White);
    m_buttonText.setOutlineColor(sf::Color::Black);
    m_buttonText.setOutlineThickness(1);
    m_buttonText.setOrigin(m_buttonText.getLocalBounds().getCenter());

    m_buttonRect.setFillColor(sf::Color::White);
}

void Button::buttonLogic() {
    if(m_function == Function::PLAY) {
        window->state = Window::PLAY_STATE;
    } else {
        window->close();
    }
}

void Button::setSize(sf::Vector2f size) {
    m_buttonRect.setSize(size);
    m_buttonRect.setOrigin(m_buttonRect.getLocalBounds().getCenter());
}

void Button::setPosition(sf::Vector2f pos) {
    m_buttonRect.setPosition(pos);
    m_buttonText.setPosition({ pos.x + m_textOffsetX, pos.y + m_textOffsetY });
}

sf::Vector2f Button::getSize() const {
    return m_buttonRect.getSize();
}

void Button::draw() {
    window->draw(m_buttonRect);
    window->draw(m_buttonText);
}


void Button::update() {
    auto buttonPressed = [this]() {
        const auto* mousePressed = window->event->getIf<sf::Event::MouseButtonPressed>();
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
        m_clock.start();
        m_buttonRect.setFillColor(s_clicked);
    }

    // Reset the color after clicking
    if(!m_clock.isRunning()) {
        // Button hover effect
        m_buttonRect.getGlobalBounds().contains(
        (sf::Vector2f)sf::Mouse::getPosition(*window)) ?
        m_buttonRect.setFillColor(s_hovered) :
        m_buttonRect.setFillColor(s_default);
    } else {
        sf::Time time = m_clock.getElapsedTime();

        // Set color to green when pressed
        if(time.asMilliseconds() >= 100) {
            m_buttonRect.setFillColor(s_hovered);
        }

        // Delay the function of button
        if(time.asMilliseconds() >= 200) {
            buttonLogic();
            m_clock.reset();
        }
    }
}

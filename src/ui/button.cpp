#include <core/engine.hpp>
#include <ui/button.hpp>

game::Button::Button(ButtonFunction function, sf::String text, uint charSize, sf::Vector2f offset)
: m_textOffsetX(offset.x), m_textOffsetY(offset.y), m_function(function) {
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

void game::Button::m_buttonLogic() {
    if(m_function == game::ButtonFunction::PLAY) {
        game::state = game::State::PLAY_STATE;
    } else {
        game::window->close();
    }
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

void game::Button::draw() {
    game::window->draw(m_buttonRect);
    game::window->draw(m_buttonText);
}


void game::Button::update() {
    // Button hover effect
    if(!clock.isRunning()) {
        m_buttonRect.getGlobalBounds().contains(
        (sf::Vector2f)sf::Mouse::getPosition(*game::window)) ?
        m_buttonRect.setFillColor(s_hovered) :
        m_buttonRect.setFillColor(s_default);
    }

    auto buttonPressed = [this]() {
        const auto* mousePressed = game::event->getIf<sf::Event::MouseButtonPressed>();
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
        m_buttonRect.setFillColor(s_clicked);
    }

    // Reset the color after clicking
    if(clock.isRunning()) {
        sf::Time time = clock.getElapsedTime();

        // Hover effect timer and delay for button logic
        if(time.asMilliseconds() >= 300) {
            m_buttonLogic();
            clock.reset();
        } else if(time.asMilliseconds() >= 100) {
            m_buttonRect.setFillColor(s_hovered);
        }
    }
}

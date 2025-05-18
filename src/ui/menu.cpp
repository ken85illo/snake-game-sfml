#include "menu.hpp"

game::Menu::Menu(sf::RenderWindow* window) : m_window(window) {
    // Initialize the title text to center
    m_initTitleText();

    // Initialize the start button to center
    m_initButtonText(m_startButton, 300, m_startButtonSize);

    // Initialize the quit button to center
    m_initButtonText(m_quitButton, 400, m_quitButtonSize);
}

void game::Menu::m_initTitleText() {
    m_titleText.setCharacterSize(m_titleTextSize);
    m_titleText.setOrigin(m_titleText.getLocalBounds().getCenter());
    m_titleText.setFillColor(sf::Color(0x06F02BFF)); // Darkish Green
    m_titleText.setPosition({ m_window->getSize().x / 2.f, 150 }); // Center of the window
    m_titleText.setOutlineThickness(2);
    m_titleText.setOutlineColor(sf::Color(0x3C4142FF)); // Charcoal Gray
}

void game::Menu::m_initButtonText(game::Button& button, float yPos, sf::Vector2f size) {
    const float windowWidth = m_window->getSize().x;

    button.setSize(size);
    button.setPosition({ m_window->getSize().x / 2.f, yPos }); // Center of the Window
}

void game::Menu::draw() {
    m_window->draw(m_titleText);
    m_window->draw(m_sfmlText);
    m_startButton.draw(m_window);
    m_quitButton.draw(m_window);
}

void game::Menu::update(const std::optional<sf::Event>& event) {
    m_startButton.update(event, m_window);
    m_quitButton.update(event, m_window);
}

#include "menu.hpp"
#include <engine.hpp>

Menu::Menu() {

    // Initialize the title text to center
    initTitleText(200);

    // Initialize the start button to center
    initButtonText(m_startButton, 350, m_startButtonSize);

    // Initialize the quit button to center
    initButtonText(m_quitButton, 450, m_quitButtonSize);
}

void Menu::initTitleText(float yPos) {
    m_titleText.setCharacterSize(m_titleTextSize);
    m_titleText.setOrigin(m_titleText.getLocalBounds().getCenter());
    m_titleText.setFillColor(sf::Color(0x06F02BFF)); // Darkish Green
    m_titleText.setPosition({ window->getSize().x / 2.f, yPos }); // Center of the window
    m_titleText.setOutlineThickness(2);
    m_titleText.setOutlineColor(sf::Color(0x3C4142FF)); // Charcoal Gray
}

void Menu::initButtonText(Button& button, float yPos, sf::Vector2f size) {
    const float windowWidth = window->getSize().x;

    button.setSize(size);
    button.setPosition({ window->getSize().x / 2.f, yPos }); // Center of the Window
}

void Menu::draw() {
    window->draw(m_titleText);
    window->draw(m_sfmlText);
    m_startButton.draw();
    m_quitButton.draw();
}

void Menu::update() {
    m_startButton.update();
    m_quitButton.update();
}

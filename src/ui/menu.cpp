#include <core/engine.hpp>
#include <ui/button.hpp>
#include <ui/menu.hpp>

game::Menu::Menu()
: m_startButton(new game::Button{ game::ButtonFunction::PLAY, "PLAY", m_buttonTextSize }),
  m_quitButton(new game::Button{ game::ButtonFunction::QUIT, "QUIT", m_buttonTextSize }) {

    // Initialize the title text to center
    m_initTitleText(200);

    // Initialize the start button to center
    m_initButtonText(m_startButton, 350, m_startButtonSize);

    // Initialize the quit button to center
    m_initButtonText(m_quitButton, 450, m_quitButtonSize);
}

game::Menu::~Menu() {
    delete m_startButton;
    delete m_quitButton;
}

void game::Menu::m_initTitleText(float yPos) {
    m_titleText.setCharacterSize(m_titleTextSize);
    m_titleText.setOrigin(m_titleText.getLocalBounds().getCenter());
    m_titleText.setFillColor(sf::Color(0x06F02BFF)); // Darkish Green
    m_titleText.setPosition({ game::window->getSize().x / 2.f, yPos }); // Center of the window
    m_titleText.setOutlineThickness(2);
    m_titleText.setOutlineColor(sf::Color(0x3C4142FF)); // Charcoal Gray
}

void game::Menu::m_initButtonText(game::Button* const button, float yPos, sf::Vector2f size) {
    const float windowWidth = game::window->getSize().x;

    button->setSize(size);
    button->setPosition({ game::window->getSize().x / 2.f, yPos }); // Center of the Window
}

void game::Menu::draw() {
    game::window->draw(m_titleText);
    game::window->draw(m_sfmlText);
    m_startButton->draw();
    m_quitButton->draw();
}

void game::Menu::update() {
    m_startButton->update();
    m_quitButton->update();
}

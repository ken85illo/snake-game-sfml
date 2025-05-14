#include <SFML/Graphics/RectangleShape.hpp>
#include <ui/window.hpp>

game::Window::Window(unsigned int width, unsigned int height, sf::String title, unsigned int numOfGrid)
: sf::RenderWindow(sf::VideoMode({ width, height }), title, m_style, m_state),
  m_numOfGrid(numOfGrid) {

    auto [desktopWidth, desktopHeight] = sf::VideoMode::getDesktopMode().size;
    auto [windowWidth, windowHeight] = this->getSize();

    this->setPosition({ static_cast<int>((desktopWidth - windowWidth) / 2),
    static_cast<int>(desktopHeight - windowHeight) / 2 });

    this->setFramerateLimit(m_framerateLimit);

    // Grid Rect
    if(numOfGrid) {
        const float gridWidth = this->getSize().x / (float)numOfGrid;
        const float gridHeight = this->getSize().y / (float)numOfGrid;

        gridRect = sf::RectangleShape({ gridWidth, gridHeight });
        gridRect.setFillColor(sf::Color::Black);
        gridRect.setOutlineThickness(1.f);
        gridRect.setOutlineColor(sf::Color::Green);
    }
}

void game::Window::gameLoop() {
    while(this->isOpen()) {
        while(const auto event = this->pollEvent()) {
            this->update(event);
        }
        this->render();
    }
}

void game::Window::update(const std::optional<sf::Event> event) {
    if(event->is<sf::Event::Closed>()) {
        this->close();
    }
}

void game::Window::render() {
    this->clear(sf::Color::Black);

    // NOTE: Render texts, shapes, and sprites here
    // --------------------------------------------
    if(m_numOfGrid) {
        drawGrid();
    }

    // --------------------------------------------

    this->display();
}

void game::Window::drawGrid() {
    auto [gridWidth, gridHeight] = gridRect.getSize();
    for(int i = 0; i < m_numOfGrid; i++) {
        for(int j = 0; j < m_numOfGrid; j++) {
            gridRect.setPosition({ gridWidth * i, gridHeight * j });
            this->draw(gridRect);
        }
    }
}

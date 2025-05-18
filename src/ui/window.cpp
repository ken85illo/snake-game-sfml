#include "window.hpp"

game::Window::Window(uint width, uint height, sf::String title, bool showGrid, uint numOfGrid)
: sf::RenderWindow(sf::VideoMode({ width, height }), title, m_style, m_state),
  m_showGrid(showGrid),
  m_numOfGrid(numOfGrid) {

    auto [desktopWidth, desktopHeight] = sf::VideoMode::getDesktopMode().size;
    auto [windowWidth, windowHeight] = this->getSize();

    this->setPosition({ (int)((desktopWidth - windowWidth) / 2),
    (int)(desktopHeight - windowHeight) / 2 });

    this->setFramerateLimit(m_framerateLimit);

    // Grid Rect
    if(numOfGrid) {
        const float gridWidth = this->getSize().x / (float)numOfGrid;
        const float gridHeight = this->getSize().y / (float)numOfGrid;

        m_gridRect = sf::RectangleShape({ gridWidth, gridHeight });
        m_gridRect.setFillColor(sf::Color::Black);
        m_gridRect.setOutlineThickness(1.f);
        m_gridRect.setOutlineColor(sf::Color(0, 255, 0, 50));
    }
}

void game::Window::gameLoop() {
    while(this->isOpen()) {
        while(const auto event = this->pollEvent()) {
            this->m_update(event);
        }
        this->m_render();
    }
}

void game::Window::m_update(const std::optional<sf::Event>& event) {
    if(event->is<sf::Event::Closed>()) {
        this->close();
    }
    mainMenu.update(event);
}

void game::Window::m_render() {
    this->clear(sf::Color::Black);

    // NOTE: Render texts, shapes, and sprites here
    // --------------------------------------------
    if(m_numOfGrid) {
        m_drawGrid();
    }

    mainMenu.draw();

    // --------------------------------------------

    this->display();
}

void game::Window::m_drawGrid() {
    auto [gridWidth, gridHeight] = m_gridRect.getSize();
    for(int i = 0; i < m_numOfGrid; i++) {
        for(int j = 0; j < m_numOfGrid; j++) {
            m_gridRect.setPosition({ gridWidth * i, gridHeight * j });
            this->draw(m_gridRect);
        }
    }
}

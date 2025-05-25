#include "window.hpp"
#include <string>

Window::Window(uint width, uint height, sf::String title, uint numOfGrid, bool showGrid)
: sf::RenderWindow(sf::VideoMode({ width, height }), title, m_style, m_state),
  m_showGrid(showGrid) {

    this->numOfGrid = numOfGrid;

    auto [desktopWidth, desktopHeight] = sf::VideoMode::getDesktopMode().size;
    auto [windowWidth, windowHeight] = this->getSize();

    this->setPosition({ (int)((desktopWidth - windowWidth) / 2),
    (int)(desktopHeight - windowHeight) / 2 });


    this->setFramerateLimit(m_framerateLimit);

    // Grid Rect
    if(numOfGrid) {
        const float gridWidth = this->getSize().x / (float)numOfGrid;
        const float gridHeight = this->getSize().y / (float)numOfGrid;

        gridSize = sf::Vector2f{ gridWidth, gridHeight };
        m_gridRect = sf::RectangleShape(gridSize);
        m_gridRect.setFillColor(sf::Color{ 0x000A00FF });
        m_gridRect.setOutlineThickness(1.f);
        m_gridRect.setOutlineColor(sf::Color{ 0x00990033 });
    }
}

Window::~Window() {
    delete m_mainMenu;
    delete m_snake;
    delete apple;
}

void Window::gameLoop() {
    m_mainMenu = new Menu{};
    m_snake = new Snake{};
    apple = new Apple{};

    while(this->isOpen()) {
        this->update();
        this->render();
    }
}

void Window::scoreUpdate() {
    std::string scoreText = "Score: ";
    m_scoreText.setString(scoreText.append(std::to_string(score)));
}

void Window::update() {
    if(state == PLAY_STATE) {
        m_snake->move();
        scoreUpdate();
    }

    while((event = this->pollEvent())) {
        if(event->is<sf::Event::Closed>())
            this->close();


        if(state == MENU_STATE)
            m_mainMenu->update();
        else
            m_snake->update();
    }
}

void Window::render() {
    this->clear(sf::Color::Black);

    // NOTE: Render texts, shapes, and sprites here
    // --------------------------------------------
    if(m_showGrid)
        drawGrid();


    if(state == MENU_STATE)
        m_mainMenu->draw();
    else {
        apple->draw();
        m_snake->draw();
        this->draw(m_scoreText);
    }

    // --------------------------------------------

    this->display();
}

void Window::drawGrid() {
    auto [gridWidth, gridHeight] = m_gridRect.getSize();
    for(int i = 0; i < numOfGrid; i++) {
        for(int j = 0; j < numOfGrid; j++) {
            m_gridRect.setPosition({ gridWidth * i, gridHeight * j });
            this->draw(m_gridRect);
        }
    }
}

#include "apple.hpp"
#include "engine.hpp"
#include "snake.hpp"
#include <ui/menu.hpp>

game::State game::state = game::State::MENU_STATE;
uint game::numOfGrid;
sf::Vector2f game::gridSize;
std::optional<sf::Event> game::event;
game::Apple* game::apple;

game::Window::Window(uint width, uint height, sf::String title, uint numOfGrid, bool showGrid)
: sf::RenderWindow(sf::VideoMode({ width, height }), title, m_style, m_state),
  m_showGrid(showGrid) {

    game::numOfGrid = numOfGrid;

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
        m_gridRect.setFillColor(sf::Color{ 0x000000FF });
        m_gridRect.setOutlineThickness(1.f);
        m_gridRect.setOutlineColor(sf::Color{ 0x009900AA });
    }
}

game::Window::~Window() {
    delete m_mainMenu;
    delete m_snake;
    delete apple;
}

void game::Window::gameLoop() {
    m_mainMenu = new Menu{};
    m_snake = new Snake{};
    apple = new Apple{};

    while(this->isOpen()) {
        this->update();
        this->render();
    }
}

void game::Window::update() {
    m_snake->move();
    while((event = this->pollEvent())) {
        if(event->is<sf::Event::Closed>()) {
            this->close();
        }

        if(state == State::MENU_STATE) {
            m_mainMenu->update();
        } else {
            m_snake->update();
        }
    }
}

void game::Window::render() {
    this->clear(sf::Color::Black);

    // NOTE: Render texts, shapes, and sprites here
    // --------------------------------------------
    if(m_showGrid) {
        drawGrid();
    }

    if(state == State::MENU_STATE) {
        m_mainMenu->draw();
    } else {
        apple->draw();
        m_snake->draw();
    }

    // --------------------------------------------

    this->display();
}

void game::Window::drawGrid() {
    auto [gridWidth, gridHeight] = m_gridRect.getSize();
    for(int i = 0; i < numOfGrid; i++) {
        for(int j = 0; j < numOfGrid; j++) {
            m_gridRect.setPosition({ gridWidth * i, gridHeight * j });
            this->draw(m_gridRect);
        }
    }
}

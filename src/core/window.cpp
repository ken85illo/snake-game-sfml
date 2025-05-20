#include <core/apple.hpp>
#include <core/engine.hpp>
#include <ui/menu.hpp>

game::State game::state = game::State::MENU_STATE;
uint game::numOfGrid;
sf::Vector2f game::gridSize;
std::optional<sf::Event> game::event;

game::Window::Window(uint width, uint height, sf::String title, bool showGrid, uint numOfGrid)
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

        game::gridSize = sf::Vector2f{ gridWidth, gridHeight };
        m_gridRect = sf::RectangleShape(game::gridSize);
        m_gridRect.setFillColor(sf::Color{ 0x000000FF });
        m_gridRect.setOutlineThickness(1.f);
        m_gridRect.setOutlineColor(sf::Color{ 0x009900AA });
    }
}

game::Window::~Window() {
    delete m_mainMenu;
    delete m_apple;
}

void game::Window::gameLoop() {
    m_mainMenu = new game::Menu{};
    m_apple = new game::Apple{};

    while(this->isOpen()) {
        while((game::event = this->pollEvent())) {
            this->m_update();
        }
        this->m_render();
    }
}

void game::Window::m_update() {
    if(game::event->is<sf::Event::Closed>()) {
        this->close();
    }

    if(game::state == game::State::MENU_STATE) {
        m_mainMenu->update();
    }
}

void game::Window::m_render() {
    this->clear(sf::Color::Black);

    // NOTE: Render texts, shapes, and sprites here
    // --------------------------------------------
    if(m_showGrid) {
        m_drawGrid();
    }

    if(game::state == game::State::MENU_STATE) {
        m_mainMenu->draw();
    } else {
        m_apple->draw();
    }

    // --------------------------------------------

    this->display();
}

void game::Window::m_drawGrid() {
    auto [gridWidth, gridHeight] = m_gridRect.getSize();
    for(int i = 0; i < game::numOfGrid; i++) {
        for(int j = 0; j < game::numOfGrid; j++) {
            m_gridRect.setPosition({ gridWidth * i, gridHeight * j });
            this->draw(m_gridRect);
        }
    }
}

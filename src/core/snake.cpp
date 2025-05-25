#include "snake.hpp"
#include <cmath>
#include <engine.hpp>

Snake::Snake() {
    m_clock.reset();
    m_bodyPart.setSize(window->gridSize);
    m_bodyPart.setFillColor(sf::Color::Green); // Body

    for(int i = 0; i < m_initialSize; i++) {
        float center = std::floor(window->numOfGrid / 2) * window->gridSize.x; // The same as gridSize.y
        m_bodyPart.setPosition({ center, center + window->gridSize.x * i });
        m_snake.push_back(m_bodyPart);
    }

    m_snake[0].setFillColor(sf::Color::Yellow); // Head
    m_clock.start();
}

void Snake::draw() {
    for(auto& rect : m_snake) {
        window->draw(rect);
    }
}


void Snake::move() {
    const uint currentTime = m_clock.getElapsedTime().asMilliseconds();

    if(delay && currentTime <= delayVal)
        return;
    else
        delay = false;


    if(currentTime >= (1000 / m_movesPerSecond)) {
        for(int i = m_snake.size() - 1; i >= 1; i--) {
            m_snake[i].setPosition(m_snake[i - 1].getPosition());
        }

        m_snake[0].move({ window->gridSize.x * m_horizontalMove,
        window->gridSize.y * m_verticalMove });

        m_clock.restart();
    }

    auto headPosition = m_snake[0].getPosition();
    auto windowSize = (sf::Vector2f)window->getSize();

    // Reset x position when going out of the right or left side of the window
    if(headPosition.x < 0.0f)
        m_snake[0].setPosition({ windowSize.x - window->gridSize.x, headPosition.y });

    if(headPosition.x > windowSize.x)
        m_snake[0].setPosition({ 0.f, headPosition.y });


    // Reset x position when going out of the right or left side of the window
    if(headPosition.y < 0.0f)
        m_snake[0].setPosition({ headPosition.x, windowSize.y - window->gridSize.y });

    if(headPosition.y > windowSize.y)
        m_snake[0].setPosition({ headPosition.x, 0.f });


    // Check Collision with Apple
    auto applePos = window->apple->getGlobalBounds().getCenter();
    if(m_snake[0].getGlobalBounds().contains(applePos)) {
        window->apple->update();
        m_bodyPart.setPosition(m_snake.back().getPosition());
        m_snake.push_back(m_bodyPart);
        window->score++;
    }
}

void Snake::update() {
    auto keyPressed = window->event->getIf<sf::Event::KeyPressed>();

    if(!keyPressed) {
        return;
    }

    if(m_verticalMove) {
        // If the snake is moving vertically then only permit moves left and right
        switch(keyPressed->scancode) {
        case sf::Keyboard::Scancode::A:
        case sf::Keyboard::Scancode::Left:
            m_verticalMove = 0.f;
            m_horizontalMove = -1.f;
            break;
        case sf::Keyboard::Scancode::D:
        case sf::Keyboard::Scancode::Right:
            m_verticalMove = 0.f;
            m_horizontalMove = 1.f;
            break;
        default: break;
        }
    } else if(m_horizontalMove) {
        // If the snake is moving horizontally then only permit moves up and down
        switch(keyPressed->scancode) {
        case sf::Keyboard::Scancode::W:
        case sf::Keyboard::Scancode::Up:
            m_verticalMove = -1.f;
            m_horizontalMove = 0.f;
            break;
        case sf::Keyboard::Scancode::S:
        case sf::Keyboard::Scancode::Down:
            m_verticalMove = 1.f;
            m_horizontalMove = 0;
            break;
        default: break;
        }
    }
}

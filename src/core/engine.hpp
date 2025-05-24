#pragma once

#include <SFML/Graphics.hpp>
#include <core/window.hpp>

namespace game {

class Apple;

enum State {
    MENU_STATE,
    PLAY_STATE,
};

extern State state;
extern uint numOfGrid;
extern sf::Vector2f gridSize;
extern std::optional<sf::Event> event;
extern Window window;
extern Apple* apple;

} // namespace game

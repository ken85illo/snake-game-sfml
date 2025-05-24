#include <core/engine.hpp>

game::Window game::window{ 800, 800, "SNAKE GAME SFML", 60 };

int main() {
    game::window.gameLoop();
}

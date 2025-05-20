#include <core/engine.hpp>

game::Window* game::window;

int main() {
    game::window = new game::Window{ 800, 800, "SNAKE GAME SFML", true };
    game::window->gameLoop();
    delete game::window;
}

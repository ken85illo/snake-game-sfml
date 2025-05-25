#include <engine.hpp>

Window* window;

int main() {
    window = new Window{ 800, 800, "SNAKE GAME SFML", 60, true };
    window->gameLoop();
    delete window;
}

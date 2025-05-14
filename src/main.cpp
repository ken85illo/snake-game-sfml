#include <ui/window.hpp>

int main() {
    game::Window window(800, 800, "Snake Game SFML", 50);
    window.gameLoop();
}

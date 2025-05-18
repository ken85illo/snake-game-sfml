#include <ui/window.hpp>

int main() {
    game::Window window(800, 800, "Snake Game SFML", true);
    window.gameLoop();
}

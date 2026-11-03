#include "Core/Game.hpp"

int main() {
    NoliEngine::Game game;
    if (!game.initialize("NoliEngine v3", 960, 540))
        return 1;

    game.run();
    return 0;
}

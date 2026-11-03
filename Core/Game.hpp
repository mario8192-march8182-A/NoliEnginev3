#pragma once

#include <SDL.h>
#include <memory>

namespace NoliEngine {

class Scene;

class Game {
public:
    Game() = default;
    ~Game();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    bool initialize(const char* title, int width, int height);
    void run();

private:
    void shutdown();

    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    bool running_ = false;
    std::unique_ptr<Scene> scene_;
};

} // namespace NoliEngine

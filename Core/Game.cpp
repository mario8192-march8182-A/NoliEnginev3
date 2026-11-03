#include "Game.hpp"
#include "Scene.hpp"

#include <iostream>

namespace NoliEngine {

Game::~Game() {
    shutdown();
}

bool Game::initialize(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::cerr << "SDL_Init: " << SDL_GetError() << '\n';
        return false;
    }

    window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               width, height, SDL_WINDOW_SHOWN);
    if (!window_) {
        std::cerr << "SDL_CreateWindow: " << SDL_GetError() << '\n';
        shutdown();
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        std::cerr << "SDL_CreateRenderer: " << SDL_GetError() << '\n';
        shutdown();
        return false;
    }

    scene_ = std::make_unique<Scene>();
    running_ = true;
    return true;
}

void Game::run() {
    Uint64 previous = SDL_GetPerformanceCounter();

    while (running_) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
                running_ = false;
        }

        const Uint64 now = SDL_GetPerformanceCounter();
        const float deltaTime = static_cast<float>(now - previous) /
                                static_cast<float>(SDL_GetPerformanceFrequency());
        previous = now;

        if (scene_)
            scene_->update(deltaTime);

        SDL_SetRenderDrawColor(renderer_, 24, 24, 32, 255);
        SDL_RenderClear(renderer_);
        if (scene_)
            scene_->render(renderer_);
        SDL_RenderPresent(renderer_);
    }
}

void Game::shutdown() {
    scene_.reset();
    if (renderer_) {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }
    if (window_) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
    SDL_Quit();
    running_ = false;
}

} // namespace NoliEngine

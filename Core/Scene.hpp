#pragma once

#include <SDL.h>
#include <memory>
#include <vector>

namespace NoliEngine {

class GameObject;

class Scene {
public:
    Scene();
    void update(float deltaTime);
    void render(SDL_Renderer* renderer) const;

private:
    std::vector<std::unique_ptr<GameObject>> objects_;
};

} // namespace NoliEngine

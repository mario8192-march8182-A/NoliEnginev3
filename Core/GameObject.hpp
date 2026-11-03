#pragma once

#include <SDL.h>

namespace NoliEngine {

class GameObject {
public:
    GameObject(float x, float y, float width, float height);
    void update(float deltaTime);
    void render(SDL_Renderer* renderer) const;

private:
    float x_;
    float y_;
    float width_;
    float height_;
};

} // namespace NoliEngine

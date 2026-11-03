#include "GameObject.hpp"

namespace NoliEngine {

GameObject::GameObject(float x, float y, float width, float height)
    : x_(x), y_(y), width_(width), height_(height) {}

void GameObject::update(float deltaTime) {
    (void)deltaTime; // Add object behavior here.
}

void GameObject::render(SDL_Renderer* renderer) const {
    const SDL_Rect bounds{static_cast<int>(x_), static_cast<int>(y_),
                          static_cast<int>(width_), static_cast<int>(height_)};
    SDL_SetRenderDrawColor(renderer, 240, 80, 90, 255);
    SDL_RenderFillRect(renderer, &bounds);
}

} // namespace NoliEngine

#include "Scene.hpp"
#include "GameObject.hpp"

namespace NoliEngine {

Scene::Scene() {
    // Placeholder object so the new SDL core shows something when launched.
    objects_.push_back(std::make_unique<GameObject>(120.0F, 120.0F, 64.0F, 64.0F));
}

void Scene::update(float deltaTime) {
    for (const auto& object : objects_)
        object->update(deltaTime);
}

void Scene::render(SDL_Renderer* renderer) const {
    for (const auto& object : objects_)
        object->render(renderer);
}

} // namespace NoliEngine

#include "Scene.hpp"
#include "DisplayManager.hpp"
#include "Entity.hpp"
#include "GameController.hpp"
#include "objects/BallDude.hpp"
#include <algorithm>

Scene::Scene(DisplayManager *displayManager, GameController *gameController)
    : displayManager(displayManager), gameController(gameController),
      running(true) {
    init();
}

Scene::~Scene() { clean(); }

void Scene::init() {
    auto ballDude =
        std::make_unique<BallDude>(displayManager, gameController, 200, 200);
    addEntity(std::move(ballDude));
}

void Scene::update() {
    for (auto &entity : entities) {
        entity->update();
    }
}

void Scene::render() {
    for (auto &entity : entities) {
        entity->render();
    }
}

void Scene::clean() {
    for (auto &entity : entities) {
        entity->clean();
    }
    entities.clear();
}

void Scene::addEntity(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void Scene::removeEntity(Entity *entity) {
    entities.erase(std::remove_if(entities.begin(), entities.end(),
                                  [entity](const std::unique_ptr<Entity> &e) {
                                      return e.get() == entity;
                                  }),
                   entities.end());
}

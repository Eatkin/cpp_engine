#include "Scene.hpp"
#include "DisplayManager.hpp"
#include "Entity.hpp"
#include "GameController.hpp"
#include "objects/Rectangle.hpp"
#include <algorithm>

Scene::Scene(DisplayManager *displayManager, GameController *gameController)
    : displayManager(displayManager), gameController(gameController),
      running(true) {
    init();
}

Scene::~Scene() { clean(); }

void Scene::init() {
    auto rectangle = std::make_unique<Rectangle>(
        displayManager, gameController, 0, 0, 100, 100, 255, 0, 0, 255);
    addEntity(std::move(rectangle));
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

#include "Entity.hpp"
#include "Component.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"
#include "components/PositionComponent.hpp"

// Unique id for each entity
int Entity::nextId = 0;

Entity::Entity(DisplayManager *displayManager, GameController *gameController)
    : displayManager(displayManager), gameController(gameController) {
    init();
}

Entity::~Entity() { clean(); }

void Entity::init() { id = nextId++; }

void Entity::update() {
    for (auto &component : components) {
        component->update();
    }
    deltaTime = gameController->getDeltaTime();
}

void Entity::render() {
    for (auto &component : components) {
        component->render();
    }
}

std::pair<float, float> Entity::getPosition() {
    if (auto *position = getComponent<PositionComponent>()) {
        return {position->x, position->y};
    }
    return {0.0f, 0.0f};
}

void Entity::clean() {}

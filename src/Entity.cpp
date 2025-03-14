#include "Entity.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"

// Unique id for each entity
int Entity::nextId = 0;

Entity::Entity(DisplayManager *displayManager, GameController *gameController)
    : displayManager(displayManager), gameController(gameController) {
    init();
}

Entity::~Entity() { clean(); }

void Entity::init() { id = nextId++; }

void Entity::update() {}

void Entity::render() {}

void Entity::clean() {}

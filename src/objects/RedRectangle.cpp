#include "objects/RedRectangle.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"

RedRectangle::RedRectangle(DisplayManager *displayManager,
                           GameController *gameController)
    : Entity(displayManager, gameController) {}

RedRectangle::~RedRectangle() { clean(); }

void RedRectangle::init() {
    Entity::init();
    rect = {0, 0, 100, 100};
    color = {255, 0, 0, 255};
}

void RedRectangle::render() {
    Entity::render();
    auto renderer = displayManager->getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void RedRectangle::update() { Entity::update(); }

void RedRectangle::clean() { Entity::clean(); }

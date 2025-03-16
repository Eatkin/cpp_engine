#include "objects/RedRectangle.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"
#include "components/PositionComponent.hpp"
#include <iostream>

RedRectangle::RedRectangle(DisplayManager *displayManager,
                           GameController *gameController)
    : Entity(displayManager, gameController) {
    init();
    auto *position = addComponent<PositionComponent>(0.0f, 0.0f);
}

RedRectangle::~RedRectangle() { clean(); }

void RedRectangle::init() {
    Entity::init();
    color = {255, 0, 0, 255};
    auto [x, y] = getPosition();
    rect = {static_cast<int>(x), static_cast<int>(y), 100, 100};
    std::cout << "RedRectangle initialized" << std::endl;
}

void RedRectangle::render() {
    Entity::render();
    auto renderer = displayManager->getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void RedRectangle::update() {
    Entity::update();
    auto *position = getComponent<PositionComponent>();
    position->x += deltaTime * 100;
    position->y += deltaTime * 100;
    auto [x, y] = getPosition();
    rect = {static_cast<int>(x), static_cast<int>(y), 100, 100};
}
void RedRectangle::clean() { Entity::clean(); }

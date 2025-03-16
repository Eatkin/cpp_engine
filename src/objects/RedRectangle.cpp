#include "objects/RedRectangle.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"
#include <iostream>

RedRectangle::RedRectangle(DisplayManager *displayManager,
                           GameController *gameController)
    : Entity(displayManager, gameController) {
    init();
}

RedRectangle::~RedRectangle() { clean(); }

void RedRectangle::init() {
    Entity::init();
    color = {255, 0, 0, 255};
    x = 0;
    y = 0;
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
    int xx = static_cast<int>(x);
    int yy = static_cast<int>(y);
    x += deltaTime * 10;
    y += deltaTime * 10;
    rect = {static_cast<int>(x), static_cast<int>(y), 100, 100};
}
void RedRectangle::clean() { Entity::clean(); }

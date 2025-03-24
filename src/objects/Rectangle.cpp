#include "objects/Rectangle.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"
#include "components/PositionComponent.hpp"
#include <iostream>

Rectangle::Rectangle(DisplayManager *displayManager,
                     GameController *gameController, float x, float y,
                     float width, float height, Uint8 r, Uint8 g, Uint8 b,
                     Uint8 a)
    : Entity(displayManager, gameController) {
    init();
    // Create position, rectangle and colour components
    auto *position = addComponent<PositionComponent>(x, y);
    auto *rectangle = addComponent<RectangleComponent>(width, height);
    auto *colour = addComponent<ColourComponent>(r, g, b, a);
}

Rectangle::~Rectangle() { clean(); }

void Rectangle::init() {
    Entity::init();
    std::cout << "Rectangle initialized" << std::endl;
}

void Rectangle::render() {
    Entity::render();
    auto *position = getComponent<PositionComponent>();
    auto *rectangle = getComponent<RectangleComponent>();
    auto *colour = getComponent<ColourComponent>();

    if (!position || !rectangle || !colour)
        return;

    SDL_Rect rect = {static_cast<int>(position->x),
                     static_cast<int>(position->y),
                     static_cast<int>(rectangle->width),
                     static_cast<int>(rectangle->height)};

    auto renderer = displayManager->getRenderer();
    SDL_SetRenderDrawColor(renderer, colour->getColour().r,
                           colour->getColour().g, colour->getColour().b,
                           colour->getColour().a);
    SDL_RenderFillRect(renderer, &rect);
    render_end();
}

void Rectangle::update() {
    Entity::update();

    // Get our input components
    auto &input = gameController->getInputState();
    auto right = input["keyboard"]["held"][SDLK_RIGHT];
    auto left = input["keyboard"]["held"][SDLK_LEFT];
    auto up = input["keyboard"]["held"][SDLK_UP];
    auto down = input["keyboard"]["held"][SDLK_DOWN];
    // yeah this is gross whatever it works and never needs to be touched again
    int hinput = right ? left ? 0 : 1 : left ? -1 : 0;
    int vinput = down ? up ? 0 : 1 : up ? -1 : 0;
    int speed = 100;

    auto *position = getComponent<PositionComponent>();
    position->x += deltaTime * hinput * speed;
    position->y += deltaTime * vinput * speed;
    auto [x, y] = getPosition();
}
void Rectangle::clean() { Entity::clean(); }

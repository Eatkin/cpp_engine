#include "objects/BallDude.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"
#include "components/PositionComponent.hpp"
#include "components/SpriteComponent.hpp"
#include <iostream>

BallDude::BallDude(DisplayManager *displayManager,
                   GameController *gameController, float x, float y)
    : Entity(displayManager, gameController) {
    init();
    // Create position and sprite components
    auto *position = addComponent<PositionComponent>(x, y);
    auto *sprite =
        addComponent<SpriteComponent>("assets/images/ball_dude.png", 32, 32);
}

BallDude::~BallDude() { clean(); }

void BallDude::init() {
    Entity::init();
    std::cout << "BallDude initialized" << std::endl;
}

void BallDude::render() {
    Entity::render();
    auto *position = getComponent<PositionComponent>();
    auto *sprite = getComponent<SpriteComponent>();

    if (!position || !sprite)
        return;

    // Render the sprite
    auto renderer = displayManager->getRenderer();
    sprite->render(renderer);
}

void BallDude::update() {
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

    // Update position based on input
    auto *position = getComponent<PositionComponent>();
    if (position) {
        position->x += hinput * speed * deltaTime;
        position->y += vinput * speed * deltaTime;
    }
}
void BallDude::clean() {
    Entity::clean();
    std::cout << "BallDude cleaned up" << std::endl;
}

#include "KeyboardHandler.hpp"
#include <iostream>

KeyboardHandler::KeyboardHandler() { init(); }

KeyboardHandler::~KeyboardHandler() {}

void KeyboardHandler::init() {
    resetState();
    std::cout << "KeyboardHandler initialized" << std::endl;
}

void KeyboardHandler::update() { getKeyboardState(); }

void KeyboardHandler::postUpdate() {
    // Clear the key pressed and released states
    keys_pressed.clear();
    keys_released.clear();
}

void KeyboardHandler::resetState() {
    // Clear all key states
    keys_pressed.clear();
    keys_released.clear();
    keys_held.clear();
}

void KeyboardHandler::handleInput(SDL_Event &event) {
    SDL_Keycode key = event.key.keysym.sym;

    switch (event.type) {
    case SDL_KEYDOWN:
        if (keys_held[key]) {
            break;
        }
        keys_pressed[key] = true;
        keys_held[key] = true;
        break;
    case SDL_KEYUP:
        keys_released[key] = true;
        keys_held[key] = false;
        break;
    }
}

void KeyboardHandler::getKeyboardState() {
    keyboardState.clear();
    keyboardState["pressed"] = keys_pressed;
    keyboardState["released"] = keys_released;
    keyboardState["held"] = keys_held;
}

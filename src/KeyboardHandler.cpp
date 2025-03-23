#include "KeyboardHandler.hpp"
#include <iostream>

KeyboardHandler::KeyboardHandler() { init(); }

KeyboardHandler::~KeyboardHandler() {}

void KeyboardHandler::init() {
    resetState();
    std::cout << "KeyboardHandler initialized" << std::endl;
}

void KeyboardHandler::run() {
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

std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>
KeyboardHandler::getKeyboardState() {
    std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>
        state;
    state["pressed"] = keys_pressed;
    state["released"] = keys_released;
    state["held"] = keys_held;
    return state;
}

#include "InputHandler.hpp"
#include "KeyboardHandler.hpp"
#include <iostream>

InputHandler::InputHandler() { init(); }

InputHandler::~InputHandler() {}

void InputHandler::init() {
    keyboardHandler = std::make_unique<KeyboardHandler>();
    std::cout << "InputHandler initialized" << std::endl;
}

void InputHandler::run() { keyboardHandler->run(); }

void InputHandler::handleInput(SDL_Event &event) {
    // Handle input from all input handlers
    keyboardHandler->handleInput(event);
}

std::unordered_map<
    std::string,
    std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>>
InputHandler::getInputState() {
    std::unordered_map<
        std::string,
        std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>>
        state;
    state["keyboard"] = keyboardHandler->getKeyboardState();
    return state;
}

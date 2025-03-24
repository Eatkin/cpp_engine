#include "InputHandler.hpp"
#include "KeyboardHandler.hpp"
#include <iostream>

InputHandler::InputHandler() { init(); }

InputHandler::~InputHandler() {}

void InputHandler::init() {
    keyboardHandler = std::make_unique<KeyboardHandler>();
    std::cout << "InputHandler initialized" << std::endl;
}

void InputHandler::update() {
    keyboardHandler->update();
    getInputState();
}

void InputHandler::postUpdate() { keyboardHandler->postUpdate(); }

void InputHandler::handleInput(SDL_Event &event) {
    // Handle input from all input handlers
    keyboardHandler->handleInput(event);
}

void InputHandler::getInputState() {
    inputState.clear();
    inputState["keyboard"] = keyboardHandler->keyboardState;
}

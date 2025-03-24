#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "KeyboardHandler.hpp"
#include <memory>
#include <string>
#include <unordered_map>

class InputHandler {
  public:
    InputHandler();
    ~InputHandler();

    void init();
    void update();
    void postUpdate();
    void handleInput(SDL_Event &event);
    // Gross, but it works
    std::unordered_map<
        std::string,
        std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>>
        inputState;

  private:
    // Gross, but it works
    std::unordered_map<
        std::string,
        std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>>
    getInputState();
    std::unique_ptr<KeyboardHandler> keyboardHandler;
};

#endif

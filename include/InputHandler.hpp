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
    void run();

    // Gross, but it works
    std::unordered_map<
        std::string,
        std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>>
    getInputState();
    void handleInput(SDL_Event &event);

  private:
    std::unique_ptr<KeyboardHandler> keyboardHandler;
};

#endif

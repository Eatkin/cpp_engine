#ifndef KEYBOARDHANDLER_HPP
#define KEYBOARDHANDLER_HPP

#include <SDL.h>
#include <string>
#include <unordered_map>

class KeyboardHandler {
  public:
    KeyboardHandler();
    ~KeyboardHandler();

    void init();
    void run();
    void resetState();
    std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>
    getKeyboardState();
    void handleInput(SDL_Event &event);

  private:
    std::unordered_map<SDL_Keycode, bool> keys_pressed;
    std::unordered_map<SDL_Keycode, bool> keys_released;
    std::unordered_map<SDL_Keycode, bool> keys_held;
};

#endif

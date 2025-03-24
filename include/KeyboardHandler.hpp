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
    void update();
    void postUpdate();
    void resetState();
    void handleInput(SDL_Event &event);
    std::unordered_map<std::string, std::unordered_map<SDL_Keycode, bool>>
        keyboardState;

  private:
    void getKeyboardState();
    std::unordered_map<SDL_Keycode, bool> keys_pressed;
    std::unordered_map<SDL_Keycode, bool> keys_released;
    std::unordered_map<SDL_Keycode, bool> keys_held;
};

#endif

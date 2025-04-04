#ifndef DISPLAYMANAGER_HPP
#define DISPLAYMANAGER_HPP

#include <SDL.h>
#include <string>

class DisplayManager {
  public:
    DisplayManager(const std::string &title, int width, int height);
    ~DisplayManager();

    void clear();
    void present();
    void drawRect(int x, int y, int w, int h);

    // Getter functions
    SDL_Window *getWindow() const { return window; }
    SDL_Renderer *getRenderer() const { return renderer; }

    // Function to check if initialization was successful
    bool isInitialized() const {
        return window != nullptr && renderer != nullptr;
    }

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif

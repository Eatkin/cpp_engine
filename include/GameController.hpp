#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "Window.hpp"
#include <memory>

class GameController {
  public:
    GameController();
    ~GameController();

    void run(); // Starts the game loop

  private:
    void init();         // Initializes SDL and the window
    void createWindow(); // Initializes the window
    void handleEvents(); // Processes input/events
    void update();       // Updates game state
    void render();       // Draws everything
    void clean();        // Cleans up memory

    bool running;
    std::unique_ptr<Window> window;
};

#endif // GAMECONTROLLER_HPP

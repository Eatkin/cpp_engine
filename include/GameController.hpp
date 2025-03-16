#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "DisplayManager.hpp"
#include "Scene.hpp"
#include <chrono>
#include <memory>

// Forward declaration to avoid circular dependency or some shit
class Scene;

class GameController {
  public:
    GameController();
    ~GameController();

    void run(); // Starts the game loop
    float getDeltaTime() { return this->deltaTime; }; // Delta time getter

  private:
    void init();                 // Initializes SDL and the window
    void createDisplayManager(); // Initializes the window
    void handleEvents();         // Processes input/events
    void update();               // Updates game state
    void render();               // Draws everything
    void clean();                // Cleans up memory

    std::chrono::steady_clock::time_point lastTime;
    float deltaTime = 0;
    bool running;
    std::unique_ptr<DisplayManager> displayManager;
    Scene *currentScene;
};

#endif // GAMECONTROLLER_HPP

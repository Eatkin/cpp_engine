#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "DisplayManager.hpp"
#include "InputHandler.hpp"
#include "Scene.hpp"
#include <chrono>
#include <memory>

// Forward declaration to avoid circular dependency or some shit
class Scene;
class InputHandler;

class GameController {
  public:
    GameController();
    ~GameController();

    void run();                                       // Starts the game loop
    float getDeltaTime() { return this->deltaTime; }; // Delta time getter
    std::unordered_map<
        std::string, std::unordered_map<
                         std::string, std::unordered_map<SDL_Keycode, bool>>> &
    getInputState();

  private:
    void init();                 // Initializes SDL and the window
    void createDisplayManager(); // Initializes the window
    void handleEvents();         // Processes input/events
    void update();               // Updates game state
    void postUpdate();           // Any post-update cleanup jobs
    void render();               // Draws everything
    void clean();                // Cleans up memory

    std::chrono::steady_clock::time_point lastTime;
    float deltaTime = 0;
    bool running;
    std::unique_ptr<DisplayManager> displayManager;
    std::unique_ptr<Scene> currentScene;
    std::unique_ptr<InputHandler> inputHandler;
};

#endif // GAMECONTROLLER_HPP

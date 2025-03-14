#ifndef SCENE_HPP
#define SCENE_HPP

#include "DisplayManager.hpp"
#include "Entity.hpp"
#include "GameController.hpp"
#include <memory>
#include <vector>

class GameController;
class Entity;

class Scene {
  public:
    Scene(DisplayManager *displayManager, GameController *gameController);
    ~Scene();

    void init();
    void update();
    void render();
    void clean();
    void addEntity(std::unique_ptr<Entity> entity);
    void removeEntity(Entity *entity);

    bool isRunning() const { return running; }
    void stop() { running = false; }
    void start() { running = true; }

  private:
    DisplayManager *displayManager;
    GameController *gameController;
    std::vector<std::unique_ptr<Entity>> entities;
    bool running;
};

#endif

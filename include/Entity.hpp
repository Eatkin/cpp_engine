#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "DisplayManager.hpp"
#include "GameController.hpp"

// Forward declaration to make sure compiler doesn't explode into a million tiny
class GameController;

class Entity {
  public:
    Entity(DisplayManager *displayManager, GameController *gameController);
    virtual ~Entity();

    virtual void init();
    virtual void update();
    virtual void render();
    virtual void clean();

    // Assign a unique id to each entity
    int getId() { return id; }

  protected:
    static int nextId;
    int id;
    DisplayManager *displayManager;
    GameController *gameController;
};

#endif

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include "DisplayManager.hpp"
#include "GameController.hpp"
#include <memory>
#include <vector>

// Forward declaration to make sure compiler doesn't explode into a million tiny
class GameController;

class Entity {
  public:
    Entity(DisplayManager *displayManager, GameController *gameController);
    virtual ~Entity();

    template <typename T, typename... Args> T *addComponent(Args &&...args) {
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        T *ptr = component.get();
        components.push_back(std::move(component));
        return ptr;
    }

    template <typename T> T *getComponent() {
        for (auto &component : components) {
            if (auto *ptr = dynamic_cast<T *>(component.get())) {
                return ptr;
            }
        }
        return nullptr;
    }

    std::pair<float, float> getPosition();

    virtual void init();
    virtual void update();
    virtual void render();
    virtual void clean();

    // Assign a unique id to each entity
    int getId() { return id; }

  protected:
    std::vector<std::unique_ptr<Component>> components;
    float deltaTime;
    static int nextId;
    int id;
    DisplayManager *displayManager;
    GameController *gameController;
};

#endif

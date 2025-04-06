#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Entity.hpp"
#include <SDL.h>

class Entity; // Forward declaration of Entity class

class Component {
  public:
    virtual ~Component() = default;
    virtual void update() {}
    virtual void render(SDL_Renderer *renderer) {}
    virtual void clean() {}

    void setOwner(Entity *entity) { owner = entity; }
    Entity *getOwner() const { return owner; }

  protected:
    Entity *owner = nullptr; // Pointer to the entity that owns this component
};

#endif

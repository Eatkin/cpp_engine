// TODO: Parent class for all entities in the game

#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
  public:
    Entity();
    ~Entity();

    void init();
    void update();
    void render();
    void clean();
};

#endif

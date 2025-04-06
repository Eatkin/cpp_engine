#ifndef BALLDUDE_HPP
#define BALLDUDE_HPP

#include "DisplayManager.hpp"
#include "Entity.hpp"
#include "GameController.hpp"
#include "components/PositionComponent.hpp"
#include "components/SpriteComponent.hpp"

class BallDude : public Entity {
  public:
    BallDude(DisplayManager *displayManager, GameController *gameController,
             float x, float y);
    ~BallDude();

    void init() override;
    void update() override;
    void render() override;
    void clean() override;
};

#endif

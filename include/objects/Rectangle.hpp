#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "DisplayManager.hpp"
#include "Entity.hpp"
#include "GameController.hpp"
#include "components/ColourComponent.hpp"
#include "components/PositionComponent.hpp"
#include "components/RectangleComponent.hpp"

class Rectangle : public Entity {
  public:
    Rectangle(DisplayManager *displayManager, GameController *gameController,
              float x, float y, float width, float height, Uint8 r = 255,
              Uint8 g = 255, Uint8 b = 255, Uint8 a = 255);
    ~Rectangle();

    void init() override;
    void update() override;
    void render() override;
    void clean() override;
};

#endif

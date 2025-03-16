#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "Component.hpp"

class PositionComponent : public Component {
  public:
    float x, y;

    PositionComponent(float startX, float startY) : x(startX), y(startY) {}

    void update() override {}
};

#endif

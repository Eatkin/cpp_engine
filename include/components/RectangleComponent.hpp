#ifndef RECTANGLECOMPONENT_HPP
#define RECTANGLECOMPONENT_HPP

#include "Component.hpp"
#include <SDL.h>

class RectangleComponent : public Component {
  public:
    float width, height;

    RectangleComponent(float startWidth, float startHeight)
        : width(startWidth), height(startHeight) {}

    SDL_Rect getSDLRect(int x, int y) const {
        return {x, y, static_cast<int>(width), static_cast<int>(height)};
    }
};

#endif

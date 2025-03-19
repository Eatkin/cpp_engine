#ifndef COLOURCOMPONENT_HPP
#define COLOURCOMPONENT_HPP

#include "Component.hpp"
#include <SDL.h>

class ColourComponent : public Component {
  public:
    ColourComponent(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : colour({r, g, b, a}) {}

    void update() override {}

    void setColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        colour = {r, g, b, a};
    }

    SDL_Color getColour() const { return colour; }

  private:
    SDL_Color colour;
};

#endif

#ifndef REDRECTANGLE_HPP
#define REDRECTANGLE_HPP

#include "DisplayManager.hpp"
#include "Entity.hpp"
#include "GameController.hpp"

class RedRectangle : public Entity {
  public:
    RedRectangle(DisplayManager *displayManager,
                 GameController *gameController);
    ~RedRectangle();

    void init() override;
    void update() override;
    void render() override;
    void clean() override;

  private:
    SDL_Rect rect;
    SDL_Color color;
};

#endif

#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "Component.hpp"
#include "Entity.hpp"
#include "components/PositionComponent.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

class SpriteComponent : public Component {
  public:
    SpriteComponent(const std::string &texturePath, int width, int height)
        : texturePath(texturePath), width(width), height(height) {
        texture = nullptr;
    }

    void update() override {}

    const std::string &getTexturePath() const { return texturePath; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void render(SDL_Renderer *renderer) override {
        // Access the owner to get its position
        auto *position = owner->getComponent<PositionComponent>();
        if (!position) {
            // Handle the case where the PositionComponent is not found
            return;
        }

        // Load texture if not already loaded
        if (!texture) {
            load_texture(renderer);
        }
        // Check if texture is valid
        if (!texture) {
            // Handle texture loading error
            return;
        }

        SDL_Rect destRect;
        destRect.x = static_cast<int>(position->x);
        destRect.y = static_cast<int>(position->y);
        destRect.w = width;
        destRect.h = height;
        SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    }

    void clean() override {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }

    ~SpriteComponent() { clean(); }

  private:
    SDL_Texture *texture;
    std::string texturePath;
    int width;
    int height;

    void load_texture(SDL_Renderer *renderer) {
        // Load the texture from the file path
        texture = IMG_LoadTexture(renderer, texturePath.c_str());
        if (!texture) {
            // Handle texture creation error
            std::cerr << "Failed to create texture: " << SDL_GetError()
                      << std::endl;
            return;
        }
    }
};

#endif

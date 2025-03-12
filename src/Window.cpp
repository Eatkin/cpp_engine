#include "Window.hpp"
#include <SDL.h>
#include <iostream>

Window::Window(const std::string &title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
                  << std::endl;
    }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
    }
    SDL_Init(SDL_INIT_VIDEO);
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderClear(renderer);
}

void Window::present() { SDL_RenderPresent(renderer); }

void Window::drawRect(int x, int y, int w, int h) {
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
    SDL_RenderFillRect(renderer, &rect);
}

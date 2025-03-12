#include "GameController.hpp"
#include "Window.hpp"
#include <iostream>

// Constructor
GameController::GameController() : running(true), window(nullptr) { init(); }

// Destructor
GameController::~GameController() { clean(); }

// Initialize SDL and create window/renderer
void GameController::init() {
    createWindow();
    if (!window) {
        std::cerr << "Window could not be created" << std::endl;
        running = false;
    }
    if (!window || !window->isInitialized()) {
        std::cerr << "Window or renderer could not be created" << std::endl;
        running = false;
    }
}

void GameController::createWindow() {
    window = std::make_unique<Window>("My Game", 800, 600);
}

// Handle events (window close, input, etc.)
void GameController::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }
}

// Logic for updating game state goes here
void GameController::update() {}

// Render everything
void GameController::render() {
    window->clear();
    // Test drawing a rectangle
    window->drawRect(100, 100, 50, 50);
    window->present();
}

// Cleanup function
void GameController::clean() {}

// Main game loop
void GameController::run() {
    while (running) {
        handleEvents();
        update();
        render();
    }
}

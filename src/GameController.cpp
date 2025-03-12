#include "GameController.hpp"
#include "DisplayManager.hpp"
#include <iostream>

// Constructor
GameController::GameController() : running(true), displayManager(nullptr) {
    init();
}

// Destructor
GameController::~GameController() { clean(); }

// Initialize SDL and create displayManager/renderer
void GameController::init() {
    createDisplayManager();
    if (!displayManager) {
        std::cerr << "displayManager could not be created" << std::endl;
        running = false;
    }
    if (!displayManager || !displayManager->isInitialized()) {
        std::cerr << "displayManager or renderer could not be created"
                  << std::endl;
        running = false;
    }
}

void GameController::createDisplayManager() {
    displayManager = std::make_unique<DisplayManager>("My Game", 800, 600);
}

// Handle events (displayManager close, input, etc.)
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
    displayManager->clear();
    // Test drawing a rectangle
    displayManager->drawRect(100, 100, 50, 50);
    displayManager->present();
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

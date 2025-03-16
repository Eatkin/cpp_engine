#include "GameController.hpp"
#include "DisplayManager.hpp"
#include "Scene.hpp"
#include <chrono>
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

    // Create the scene
    currentScene = new Scene(displayManager.get(), this);

    std::cout << "GameController initialized" << std::endl;

    // Setup the clock
    lastTime = std::chrono::steady_clock::now();
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
void GameController::update() {
    // Calculate deltaTime
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedTime = now - lastTime;
    deltaTime = elapsedTime.count();
    lastTime = now;

    // Work down the chain of responsibility
    if (currentScene) {
        currentScene->update();
    }
}

// Render everything
void GameController::render() {
    displayManager->clear();
    if (currentScene) {
        currentScene->render();
    }
    displayManager->present();
}

// Cleanup function
void GameController::clean() {
    if (currentScene) {
        delete currentScene;
        currentScene = nullptr;
    }
    displayManager.reset();
    SDL_Quit();
}

// Main game loop
void GameController::run() {
    while (running) {
        handleEvents();
        update();
        render();
    }
}

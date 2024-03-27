#include "WindSystem.h"
#include "GridManager.h" 
#include <chrono>

class Simulation {
public:
    Simulation(int gridWidth, int gridHeight);
    void run();

private:
    void update(float deltaTime);
    void render();

    GridManager gridManager;
    WindPatternGrid windPatterns; 
    float timeSinceLastWindUpdate = 0.0f;
    const float windUpdateInterval = 5.0f; 
};

Simulation::Simulation(int gridWidth, int gridHeight) : gridManager(gridWidth, gridHeight) {
    // to do
}

void Simulation::run() {
    auto lastFrame = std::chrono::high_resolution_clock::now();
    while (true) {
        auto currentFrame = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentFrame - lastFrame).count();
        lastFrame = currentFrame;

        update(deltaTime);
        render();
    }
}

void Simulation::update(float deltaTime) {
    timeSinceLastWindUpdate += deltaTime;
    if (timeSinceLastWindUpdate >= windUpdateInterval) {

        WindSystem::updateWindPatterns(windPatterns, deltaTime);
        WindSystem::applyLocalizedWindEffect(gridManager.getGrid(), windPatterns);
        
        timeSinceLastWindUpdate = 0.0f;
    }
}

void Simulation::render() {
}

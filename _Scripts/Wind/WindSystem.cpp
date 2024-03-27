#include "WindSystem.h"

void WindSystem::applyWindEffect(Grid& grid, const WindModel& windModel) {
    Vector2 windVector = windModel.getWindVector();
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.windEffect = windVector;
        }
    }
}
void updateWindPatterns(WindPatternGrid& windPatterns, float elapsedTime) {
    for (auto& row : windPatterns) {
        for (auto& wind : row) {
            float angleChange = elapsedTime * 0.05f;
            float newAngle = std::atan2(wind.direction.y, wind.direction.x) + angleChange;
            wind.direction = {std::cos(newAngle), std::sin(newAngle)};
            wind.strength += (static_cast<float>(rand()) / RAND_MAX - 0.5f) * 0.1f;
        }
    }
}    


void applyLocalizedWindEffect(Grid& grid, const WindPatternGrid& windPatterns) {
    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[x].size(); ++y) {
            if (x < windPatterns.size() && y < windPatterns[x].size()) {
                const auto& localWind = windPatterns[x][y];
                grid[x][y].windEffect = localWind.getWindVector();
            }
        }
    }
}


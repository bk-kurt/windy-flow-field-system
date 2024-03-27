#include "GridManager.h"
#include "WindSystem.h"

GridManager::GridManager(int width, int height) : width(width), height(height) {
    initializeGrid();
}

void GridManager::initializeGrid() {
    grid.resize(height, std::vector<Cell>(width));
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.flowDirection = {0, 0};
            cell.windEffect = {0, 0};
        }
    }
}

void GridManager::setFlowDirection(const Vector2& direction) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.flowDirection = direction;
        }
    }
}

void GridManager::applyWindEffect(const WindModel& windModel) {
    WindSystem::applyWindEffect(grid, windModel);
}

void GridManager::updateCell(int x, int y, const Vector2& flowDirection) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x].flowDirection = flowDirection;
    }
}

const Grid& GridManager::getGrid() const {
    return grid;
}

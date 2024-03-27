#pragma once

#include "Grid.h"
#include <vector>

class GridManager {
public:
    GridManager(int width, int height);
    void initializeGrid();
    void setFlowDirection(const Vector2& direction);
    void applyWindEffect(const WindModel& windModel);
    void updateCell(int x, int y, const Vector2& flowDirection);
    const Grid& getGrid() const;

private:
    Grid grid;
    int width, height;
};

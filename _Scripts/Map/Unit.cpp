struct Unit {
    Vector2 position;

    void move(const Grid& grid) {

        int gridX = static_cast<int>(position.x);
        int gridY = static_cast<int>(position.y);
      
        if (gridX >= 0 && gridX < grid.size() && gridY >= 0 && gridY < grid[0].size()) {
            Vector2 effectiveDirection = grid[gridX][gridY].getEffectiveDirection();
            position = position + effectiveDirection;
        }
    }
};

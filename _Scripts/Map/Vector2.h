#pragma once

struct Vector2 {
    float x, y;

    Vector2 operator+(const Vector2& other) const {
        return {x + other.x, y + other.y};
    }
    
    void normalize() {
        float length = std::sqrt(x * x + y * y);
        if (length > 0) {
            x /= length;
            y /= length;
        }
    }
};

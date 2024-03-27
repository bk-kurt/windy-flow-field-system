#pragma once

#include "Vector2.h"

struct LocalWind {
    Vector2 direction;
    float strength;

    Vector2 getWindVector() const {
        Vector2 windVector = direction;
        windVector.normalize();
        windVector.x *= strength;
        windVector.y *= strength;
        return windVector;
    }
};

using WindPatternGrid = std::vector<std::vector<LocalWind>>;

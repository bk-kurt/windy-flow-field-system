#pragma once

#include "Vector2.h"
#include <cmath>

struct Cell {
    Vector2 flowDirection;
    Vector2 windEffect;

    Vector2 getEffectiveDirection() const {
        Vector2 effectiveDirection = flowDirection + windEffect;
        effectiveDirection.normalize();
        return effectiveDirection;
    }
};

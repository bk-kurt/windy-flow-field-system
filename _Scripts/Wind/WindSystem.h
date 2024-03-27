#pragma once
#include "Vector2.h"
#include "Cell.h"
#include "LocalWind.h"


class WindSystem {
public:
    static void applyWindEffect(Grid& grid, const WindModel& windModel);
    static void updateWindPatterns(WindPatternGrid& windPatterns, float elapsedTime);
    static void applyLocalizedWindEffect(Grid& grid, const WindPatternGrid& windPatterns);
};

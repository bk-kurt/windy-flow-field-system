struct WindModel {
    Vector2 windDirection;
    float windStrength;

    Vector2 getWindVector() const {
        Vector2 windVector = windDirection;
        windVector.normalize();
        windVector.x *= windStrength;
        windVector.y *= windStrength;
        return windVector;
    }
};

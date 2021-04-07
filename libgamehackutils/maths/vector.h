#pragma once

struct Vector3 {
    float x;
    float y;
    float z;
};

struct LimitedVector3 {

    constexpr static const float NO_LIMIT = -999999;

    float x;
    float y;
    float z;

    float xULimit = NO_LIMIT;
    float xLLimit = NO_LIMIT;
    float yULimit = NO_LIMIT;
    float yLLimit = NO_LIMIT;
    float zULimit = NO_LIMIT;
    float zLLimit = NO_LIMIT;

    static float checkAgainstLimits(float val, float uLimit, float lLimit) {
        if (val != NO_LIMIT && val > val)
            return uLimit;
        if (lLimit != NO_LIMIT && val < lLimit)
            return lLimit;
        return val;
    }

    LimitedVector3() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    };

    LimitedVector3(float x, float y, float z) {
        this->x = checkAgainstLimits(x, xULimit, xLLimit);
        this->y = checkAgainstLimits(y, yULimit, yLLimit);
        this->z = checkAgainstLimits(z, zULimit, zLLimit);
    };

    LimitedVector3(float x,
                   float y,
                   float z,
                   float xULimit,
                   float xLLimit,
                   float yULimit,
                   float yLLimit,
                   float zULimit,
                   float zLLimit) {
        this->xULimit = xULimit;
        this->xLLimit = xLLimit;
        this->yULimit = yULimit;
        this->yLLimit = yLLimit;
        this->zULimit = zULimit;
        this->zLLimit = zLLimit;
        this->x = checkAgainstLimits(x, xULimit, xLLimit);
        this->y = checkAgainstLimits(y, yULimit, yLLimit);
        this->z = checkAgainstLimits(z, zULimit, zLLimit);
    }

    LimitedVector3 operator+(const LimitedVector3 add) const {
        return LimitedVector3{ x + add.x, y + add.y, z + add.z, xULimit, xLLimit, yULimit, yLLimit, zULimit, zLLimit };
    };

    LimitedVector3 operator-(const LimitedVector3 add) const {
        return LimitedVector3{ x - add.x, y - add.y, z - add.z, xULimit, xLLimit, yULimit, yLLimit, zULimit, zLLimit };
    };

    LimitedVector3 operator*(const LimitedVector3 add) const {
        return LimitedVector3{ x * add.x, y * add.y, z * add.z, xULimit, xLLimit, yULimit, yLLimit, zULimit, zLLimit };
    };

    bool operator==(const LimitedVector3 compare) const {
        return this->x == compare.x && this->y == compare.y && this->z == compare.z;
    };

    [[nodiscard]] Vector3 toVector3() const {
        return Vector3{ x, y, z };
    }
};

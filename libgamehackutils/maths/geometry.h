#pragma once

#include <cmath>
#include "vector.h"

static const float PI = 3.14159265359;

static float getDistance(const LimitedVector3& coord1, const LimitedVector3& coord2) {
    Vector3 delta{ coord2.x - coord1.x, coord2.y - coord1.y, coord2.z - coord1.z };
    return sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
}

static LimitedVector3 getFacingToVector(const LimitedVector3& source, const LimitedVector3& target) {

    float pitch;
    float yaw;

    float distance = getDistance(source, target);

    pitch = asin((target.z - source.z) / distance) * (180 / PI);
    yaw = atan2((target.y - source.y), (target.x - source.x)) * (180 / PI);

    return LimitedVector3{ yaw, pitch, 0, source.xULimit > target.xULimit ? source.xULimit : target.xULimit,
                           source.xLLimit < target.xLLimit ? source.xLLimit : target.xLLimit,
                           source.yULimit > target.yULimit ? source.yULimit : target.yULimit,
                           source.yLLimit < target.yLLimit ? source.yLLimit : target.yLLimit,
                           source.zULimit > target.zULimit ? source.zULimit : target.zULimit,
                           source.zLLimit < target.zLLimit ? source.zLLimit : target.zLLimit };

}

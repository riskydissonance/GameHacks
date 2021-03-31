#pragma once

#include "vector.h"
#include <cmath>

static const float PI = 3.14159265359;

/*static LimitedVector3 getDistance(const LimitedVector3 coord1, const LimitedVector3 coord2) {
    return LimitedVector3{ sqrtf(coord1.x * coord2.x),
                           sqrtf(coord1.y * coord2.y),
                           sqrtf(coord1.z * coord2.z),
                           coord1.xULimit > coord2.xULimit ? coord1.xULimit : coord2.xULimit,
                           coord1.xLLimit < coord2.xLLimit ? coord1.xLLimit : coord2.xLLimit,
                           coord1.yULimit > coord2.yULimit ? coord1.yULimit : coord2.yULimit,
                           coord1.yLLimit < coord2.yLLimit ? coord1.yLLimit : coord2.yLLimit,
                           coord1.zULimit > coord2.zULimit ? coord1.zULimit : coord2.zULimit,
                           coord1.zLLimit < coord2.zLLimit ? coord1.zLLimit : coord2.zLLimit };
}*/

static float getDistance(const LimitedVector3& coord1, const LimitedVector3& coord2) {
    Vector3 delta{coord2.x - coord1.x, coord2.y - coord1.y, coord2.z - coord1.z};
    return sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
}

static LimitedVector3 getFacingToVector(const LimitedVector3& source, const LimitedVector3& target) {

    float pitch;
    float yaw;

    float distance = getDistance(source, target);

    pitch = -asin((target.z - source.z) / distance) * (180 / PI);
    yaw = atan2((target.y - source.y), (target.x - source.x)) * (180 / PI);

    yaw += 270;

    return LimitedVector3{ yaw, pitch, 0, source.xULimit > target.xULimit ? source.xULimit : target.xULimit,
                           source.xLLimit < target.xLLimit ? source.xLLimit : target.xLLimit,
                           source.yULimit > target.yULimit ? source.yULimit : target.yULimit,
                           source.yLLimit < target.yLLimit ? source.yLLimit : target.yLLimit,
                           source.zULimit > target.zULimit ? source.zULimit : target.zULimit,
                           source.zLLimit < target.zLLimit ? source.zLLimit : target.zLLimit };

}

//
//  CircleCollider.cpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 21/05/16.
//
//

#include <complex>
#include "CircleCollider.hpp"

using namespace physics;

CircleCollider::CircleCollider() : CircleCollider(Vector(), 0) {
    
}

CircleCollider::CircleCollider(Vector center, float radius) : center(center), radius(radius) {
    
}

void CircleCollider::setCenter(Vector center) {
    this->center = center;
}

Vector CircleCollider::getCenter() const {
    return this->center;
}

void CircleCollider::setRadius(float radius) {
    this->radius = radius;
}

float CircleCollider::getRadius() const {
    return this->radius;
}

bool CircleCollider::raycast(Ray ray, float maxDistance) {
    auto rb = getAttachedRigidbody();
    auto centerAbsPosition = center;
    if (rb != nullptr) {
        centerAbsPosition += rb->getCenter();
    }
    
    auto distToOrigin = distance(ray.origin, centerAbsPosition);
    // do not continue the calculation if it's just too far away
    if (distToOrigin > (maxDistance + radius)) {
        return false;
    }
    
    // Calculate the intersection of ray and circle
    // Let's say the ray is from point (x_1, y_1) to point (x_2, y_2).
    // And for any point (x, y) on the ray, we hava:
    //     x = t * (x_2 - x_1) + x_1      (1)
    //     y = t * (y_2 - y_1) + y_1      (2)
    // where t ∈ [0, 1].
    // Also, the circle is:
    //     (x - m)^2 + (y - n)^2 = r^2    (3)
    //
    // Now we try to solve equations (1), (2) & (3), and we will get:
    //     a * t^2 + b * t + c = 0
    // If t exists, then the ray does hit the cirle on point (x, y).
    
    auto rayV = ray.direction * maxDistance; // rayV == (x_2 - x_1, y_2 - y_1)
    auto o2cV = ray.origin - centerAbsPosition; // o2cV == (x_1 - m, y_1 - n)
    auto a = maxDistance * maxDistance;
    auto b = 2 * (rayV * o2cV);
    auto c = o2cV.normSq() - radius * radius;
    auto delta = b * b - 4 * a * c;
    
    if (delta < 0) { // no real root
        return false;
    } else if (delta == 0) { // one real root
        auto t = - b / 2 / a;
        if (0 <= t && t <= 1) {
            return true;
        }
    } else { // two real roots
        auto t1 = (- b - std::sqrt(delta)) / 2 / a;
        auto t2 = (- b + std::sqrt(delta)) / 2 / a;
        if ((0 <= t1 && t1 <= 1) || (0 <= t2 && t2 <= 1)) {
            return true;
        }
    }
    
    return false;
}
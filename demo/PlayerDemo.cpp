//
//  PlayerDemo.cpp
//  GameJamPhysics
//
//  Created by Xiaxing SHI on 07/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#include "PlayerDemo.hpp"
#include <complex>

PlayerDemo::PlayerDemo(float radius, physics::Vector velocity)
: sf::CircleShape(radius), v(velocity), forceValue(5.0f), landed(false) {
    setOrigin(radius, radius);
    force = physics::Vector(0, 0);
}

bool PlayerDemo::isLanded() const {
    return landed;
}

void PlayerDemo::setLanded(bool value) {
    landed = value;
}

float PlayerDemo::getMass() const {
    return 1.0f;
}

float PlayerDemo::getRigidbodyRadius() const {
    return getRadius();
}

void PlayerDemo::setVelocity(physics::Vector velocity) {
    v = velocity;
}

physics::Vector PlayerDemo::getVelocity() const {
    return v;
}

physics::Vector PlayerDemo::getCenter() const {
    auto point = getPosition();
    return physics::Vector(point.x, point.y);
}

void PlayerDemo::moveByForce(float x, float y) {
    move(x, y);
}

void PlayerDemo::setRotationByGravity(float degree) {
    setRotation(degree);
}

void PlayerDemo::setLandedSource(physics::Vector center) {
    landCenter = center;
}

physics::Vector PlayerDemo::getForce() const {
    return force;
}

void PlayerDemo::setForceValue(float f) {
    forceValue = f;
}

float PlayerDemo::getForceValue() {
    return forceValue;
}

void PlayerDemo::setForce(float directionX, float directionY) {
    force.x = directionX;
    force.y = directionY;
    if (directionX != 0 || directionY != 0) {
        float length = std::sqrt(directionX * directionX + directionY * directionY);
        force = force / length * forceValue;
        setLanded(false);
    }
}

void PlayerDemo::jump() {
    if (isLanded()) {
        setLanded(false);
        auto vectorF = getCenter() - landCenter;
        auto dist = std::sqrt(vectorF.x * vectorF.x + vectorF.y * vectorF.y);
        vectorF = vectorF / dist * forceValue * 1.5f; // normalize the vector and then apply 1.5 * force for jump
        force = vectorF;
    }
}
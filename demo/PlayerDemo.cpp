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
: sf::CircleShape(radius), physics::Rigidbody(), forceValue(5.0f) {
    setOrigin(radius, radius);
    rbSetExtraForce(physics::Vector(0, 0));
    rbSetVelocity(velocity);
    rbSetBounciness(1);
}

PlayerDemo::~PlayerDemo() {
    
}

physics::Vector PlayerDemo::rbGetCenter() const {
    auto point = getPosition();
    return physics::Vector(point.x, point.y);
}

void PlayerDemo::rbMove(float x, float y) {
    move(x, y);
}

void PlayerDemo::rbSetRotation(float degree) {
    setRotation(degree);
}

void PlayerDemo::setForceValue(float f) {
    forceValue = f;
}

float PlayerDemo::getForceValue() {
    return forceValue;
}

void PlayerDemo::setForce(float directionX, float directionY) {
    auto force = physics::Vector(directionX, directionY);
    if (directionX != 0 || directionY != 0) {
        force = force.normalize() * forceValue;
        rbSetUseGravity(true);
    }
    rbSetExtraForce(force);
}

void PlayerDemo::jump() {
    if (!rbIsUsingGravity()) {
        rbSetUseGravity(true);
        auto force = (rbGetCenter() - landCenter).normalize();
        force *= forceValue * 1.5f; // normalize the vector and then apply 1.5 * force for jump
        rbSetExtraForce(force);
    }
}
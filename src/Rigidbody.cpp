//
//  Rigidbody.cpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 22/05/16.
//
//

#include "Rigidbody.hpp"

using namespace physics;

Rigidbody::Rigidbody() : useGravity(true), velocity(Vector()), mass(1), bounciness(0.5f), extraForce(Vector()), isInCollision(false) {
    
}

Rigidbody::~Rigidbody() {
    
}

void Rigidbody::rbSetUseGravity(bool value) {
    this->useGravity = value;
}

bool Rigidbody::rbIsUsingGravity() const {
    return this->useGravity;
}

void Rigidbody::rbSetMass(float mass) {
    this->mass = mass;
}

float Rigidbody::rbGetMass() const {
    return this->mass;
}

void Rigidbody::rbSetBounciness(float bounciness) {
    bounciness = bounciness < 0 ? 0 : bounciness;
    bounciness = bounciness > 1 ? 1 : bounciness;
    this->bounciness = bounciness;
}

float Rigidbody::rbGetBounciness() const {
    return this->bounciness;
}

void Rigidbody::rbSetVelocity(Vector velocity) {
    this->velocity = velocity;
}

Vector Rigidbody::rbGetVelocity() const {
    return this->velocity;
}

void Rigidbody::rbSetExtraForce(Vector force) {
    this->extraForce = force;
}


Vector Rigidbody::rbGetExtraForce() const {
    return this->extraForce;
}

void Rigidbody::rbSetInCollision(bool value) {
    this->isInCollision = value;
}

bool Rigidbody::rbIsInCollision() {
    return this->isInCollision;
}
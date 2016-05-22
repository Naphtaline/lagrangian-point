//
//  Collider.cpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 21/05/16.
//
//

#include "Collider.hpp"

using namespace physics;

Collider::Collider() : attachedRigidbody(nullptr), trigger(false) {
    
}

Collider::~Collider() {

}

void Collider::setAttachedRigidbody(std::shared_ptr<physics::Rigidbody> rigidbody) {
    this->attachedRigidbody = rigidbody;
}

std::shared_ptr<physics::Rigidbody> Collider::getAttachedRigidbody() const {
    return this->attachedRigidbody;
}

void Collider::setTrigger(bool trigger) {
    this->trigger = trigger;
}

bool Collider::isTrigger() const {
    return this->trigger;
}
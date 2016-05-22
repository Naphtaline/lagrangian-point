//
//  Engine.cpp
//  GameJamPhysics
//
//  Created by Xiaxing SHI on 07/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//
#include <complex>
#include <cmath>
#include <cfloat>
#include <climits>
#include "Engine.hpp"

using namespace physics;

float vectorToDegree(Vector vector);

Engine::Engine() : maxVelocity(FLT_MAX), minX(INT_MIN), minY(INT_MIN), maxX(INT_MAX), maxY(INT_MAX), bounceRateForMovementArea(0.1f), clock(nullptr) {

}

Engine::~Engine() {

}

Engine& Engine::get() {
    static Engine instance;
    return instance;
}

uint32_t Engine::addRigidbody(std::shared_ptr<Rigidbody> rigidbody) {
    uint32_t handle = 0;
    if (rigidbody != nullptr) {
        handle = nextHandle++;
        rigidbodies[handle] = rigidbody;
    }
    return handle;
}

void Engine::removeRigidbody(uint32_t handleRigidbody) {
    if (rigidbodies.find(handleRigidbody) != rigidbodies.end()) {
        rigidbodies.erase(handleRigidbody);
    }
}

uint32_t Engine::addGravity(std::shared_ptr<GravitySource> gravity) {
    uint32_t handle = 0;
    if (gravity != nullptr) {
        handle = nextHandle++;
        gravities[handle] = gravity;
    }
    return handle;
}

void Engine::removeGravity(uint32_t handleGravity) {
    if (gravities.find(handleGravity) != gravities.end()) {
        gravities.erase(handleGravity);
    }
}

void Engine::setMaxVelocity(float v) {
    maxVelocity = v;
}

void Engine::setMovementArea(int minX, int minY, int maxX, int maxY) {
    this->minX = minX;
    this->minY = minY;
    this->maxX = maxX;
    this->maxY = maxY;
}

void Engine::setBounceRateForMovementArea(float rate) {
    rate = rate < 0 ? 0 : rate;
    rate = rate > 1 ? 1 : rate;
    bounceRateForMovementArea = rate;
}

void Engine::update() {
    if (clock == nullptr) {
        clock = std::make_shared<Clock>();
    }
    auto deltaTime = clock->restart();
    for (auto rigidPair : rigidbodies) {
        auto rigid = rigidPair.second;

        auto newV = rigid->rbGetVelocity(); // new velocity
        auto force = rigid->rbGetExtraForce();
        auto mass = rigid->rbGetMass();
        auto vForce = force / mass;

        auto gravityA = Vector(); // new acceleration
        // calculate gravity
        if (rigid->rbIsUsingGravity()) {
//            auto rigidRadius = rigid->getRigidbodyRadius();
//            auto landedCenter = Vector();
            // calculate gravities
            for (auto gravityPair : gravities) {
                auto gravity = gravityPair.second;
                auto dist = distance(rigid->rbGetCenter(), gravity->getCenter());
                
                if (gravity->getMaxDistance() >= dist) { // rigidbody is in gravity field
                    float a = gravity->getAcceleration();

                    if (gravity->getMinDistance() < dist) { // rigidbody is between max & min distance
                        float minDistSrq = gravity->getMinDistance() * gravity->getMinDistance();
                        a = a * minDistSrq / dist / dist;
//                    } else if (gravity->getGravityRadius() + rigidRadius < dist) {
//                        a = a * (dist - gravity->getGravityRadius()) / (gravity->getMinDistance() - gravity->getGravityRadius());
//                    } else {
//                        if (vForce.x == 0 && vForce.y == 0) {
//                            a = 0;
//                            rigid->rbSetUseGravity(false);
//                            rigid->setLandedSource(gravity->getCenter());
//                            landedCenter = gravity->getCenter();
//                        }
//                    }
                    }

                    Vector vectorA = (gravity->getCenter() - rigid->rbGetCenter()) / dist * a;
                    gravityA += vectorA;
                }
            }

            if (gravityA.x != 0 || gravityA.y != 0) {
                rigid->rbSetRotation(vectorToDegree(gravityA));
            }

            newV += gravityA;
//            if (!rigid->rbIsUsingGravity()) {
//                newV = Vector();
//                rigid->rbSetRotation(vectorToDegree(landedCenter - rigid->rbGetCenter()));
//            }
        }
        
        // limit rigidbody in the movement area of engine
        auto bouniness = std::min(bounceRateForMovementArea, rigid->rbGetBounciness());
        auto rigidCenter = rigid->rbGetCenter();
        if (rigidCenter.x < minX && newV.x < 0) {
            newV.x = -newV.x * bouniness;
        } else if (rigidCenter.x > maxX && newV.x > 0) {
            newV.x = -newV.x * bouniness;
        }
        if (rigidCenter.y < minY && newV.y < 0) {
            newV.y = -newV.y * bouniness;
        } else if (rigidCenter.y > maxY && newV.y > 0) {
            newV.y = -newV.y * bouniness;
        }
        
        // update velocity and position
        newV += vForce;
        auto vValue = std::sqrt(newV.x * newV.x + newV.y * newV.y);
        if (vValue > maxVelocity) {
            newV *= maxVelocity / vValue;
        }

        rigid->rbSetVelocity(newV);

        newV *= deltaTime.asSeconds();

        rigid->rbMove(newV.x, newV.y);
    }
}

float vectorToDegree(Vector vector) {
    float degree = 0.0f;
    if (vector.x != 0) {
        auto radian = std::atan(vector.y / vector.x) + 1.5708f;
        if ( vector.x > 0) {
            radian += 3.1416f;
        }
        degree = radian / 3.1416f * 180;

    } else if (vector.y > 0) {
        degree = 0.0f;
    } else {
        degree = 180.0f;
    }
    
    return degree;
}

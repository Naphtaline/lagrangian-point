//
//  PlanetDemo.cpp
//  GameJamPhysics
//
//  Created by Xiaxing SHI on 07/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#include "PlanetDemo.hpp"

PlanetDemo::PlanetDemo(float x, float y, float radius)
: sf::RectangleShape(sf::Vector2f(x, y)), a(1.0f), minDist(radius*2.0f), maxDist(radius*10.0f), rForPlanet(radius) {
    setOrigin(x/2, y/2);
    

}

float PlanetDemo::getAcceleration() const {
    return a;
}

physics::Vector PlanetDemo::getCenter() const {
    auto point = getPosition();
    return physics::Vector(point.x, point.y);
}

float PlanetDemo::getGravityRadius() const {
    return rForPlanet;
}

float PlanetDemo::getMinDistance() const {
    return minDist;
}

float PlanetDemo::getMaxDistance() const {
    return maxDist;
}

void PlanetDemo::setRadiusForPlanet(float radius) {
    this->rForPlanet = radius;
}

//
//  PlanetDemo.hpp
//  GameJamPhysics
//
//  Created by Xiaxing SHI on 07/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#ifndef PlanetDemo_hpp
#define PlanetDemo_hpp

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GravitySource.hpp"
#include "Vector.hpp"

class PlanetDemo : public sf::RectangleShape, public physics::GravitySource {
public:
    float a;
    float minDist;
    float maxDist;
    float rForPlanet;
    
    PlanetDemo(float x, float y, float radius);
    // implement methods in GravitySource
    virtual float getAcceleration() const;
    virtual physics::Vector getCenter() const;
    virtual float getGravityRadius() const;
    virtual float getMinDistance() const;
    virtual float getMaxDistance() const;
    
    // others
    void setRadiusForPlanet(float radius);
};
#endif /* PlanetDemo_hpp */

//
//  PlayerDemo.hpp
//  GameJamPhysics
//
//  Created by Xiaxing SHI on 07/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#ifndef PlayerDemo_hpp
#define PlayerDemo_hpp

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Rigidbody.hpp"
#include "Vector.hpp"

class PlayerDemo : public sf::CircleShape, public physics::Rigidbody {
    physics::Vector v;
    float forceValue;
    physics::Vector force;
    
    bool landed;
    physics::Vector landCenter;
public:
    PlayerDemo(float radius, physics::Vector velocity);
    
    // implement methods in Rigidbody
    virtual bool isLanded() const;
    virtual void setLanded(bool value);
    virtual float getMass() const;
    virtual float getRigidbodyRadius() const;
    virtual void setVelocity(physics::Vector velocity);
    virtual physics::Vector getVelocity() const;
    virtual physics::Vector getCenter() const;
    virtual void moveByForce(float x, float y);
    virtual void setRotationByGravity(float degree);
    virtual void setLandedSource(physics::Vector center);
    virtual physics::Vector getForce() const;
    
    // custom methods for demo reason
    void setForceValue(float f);
    float getForceValue();
    void setForce(float directionX, float directionY);
    void jump();
};

#endif /* PlayerDemo_hpp */

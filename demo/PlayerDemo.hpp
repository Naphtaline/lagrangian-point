//
//  PlayerDemo.hpp
//  LagrangianPoint
//
//  Created by Xiaxing SHI on 07/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#ifndef PlayerDemo_hpp
#define PlayerDemo_hpp

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Rigidbody.hpp>
#include <Vector.hpp>

class PlayerDemo : public sf::CircleShape, public physics::Rigidbody {
    float forceValue;
    physics::Vector landCenter;
public:
    PlayerDemo(float radius, physics::Vector velocity);
    ~PlayerDemo();
    
    // implement methods in Rigidbody
    virtual physics::Vector rbGetCenter() const;
    virtual void rbMove(float x, float y);
    virtual void rbSetRotation(float degree);
    
    // custom methods for demo reason
    void setForceValue(float f);
    float getForceValue();
    void setForce(float directionX, float directionY);
    void jump();
};

#endif /* PlayerDemo_hpp */

//
//  Rigidbody.hpp
//  GameJamPhysics
//
//  Created by Xiaxing SHI on 06/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#ifndef Rigidbody_h
#define Rigidbody_h

#include "Vector.hpp"

namespace physics {
    
    /// \brief An interface for things that could be affected by THE LAW OF PHYSICS (only gravity for now)
    class Rigidbody {
    public:
        
        /// \brief Check whether the rigidbody is "landed" on a gravity source
        ///
        /// When a rigidbody is landed, it would not be affect by gravities anymore
        virtual bool isLanded() const = 0;
        
        /// \brief Set the rigidbody as landed
        ///
        /// This could be used to disable gravity.
        virtual void setLanded(bool value) = 0;
        
        /// \brief Not used yet
        virtual float getMass() const  = 0;
        
        /// \brief Get the radius for the rigidbody
        ///
        /// Rigidbody is treated as a circle in the Engine
        virtual float getRigidbodyRadius() const = 0;
        
        /// \brief Set the current velocity for movement
        /// \param velocity the velocity in unit/s
        virtual void setVelocity(Vector velocity) = 0;
        
        /// \brief Get the current velocity
        virtual Vector getVelocity() const  = 0;
        
        /// \brief Get the center of mass of the rigidbody
        virtual Vector getCenter() const  = 0;
        
//        /// \brief Get the head point of the rigidbody. This point defines the "positive" direction of the rigidbody
//        virtual sf::Vector2f getHeadPoint() const  = 0;
        
        /// \brief Move the rigidbody
        virtual void moveByForce(float x, float y)  = 0;
        
        /// \brief Rotate the rigidbody
        virtual void setRotationByGravity(float degree)  = 0;
        
        /// \brief Set the center of gravity source that the rigidbody landed on
        /// \param center the center of mass of the gravity source
        virtual void setLandedSource(Vector center) = 0;
        
        /// \brief Get a force would push the rigidbody
        ///
        /// This is designed for moving the rigidbody with physics
        virtual Vector getForce() const = 0;
    };
}
#endif /* Rigidbody_h */

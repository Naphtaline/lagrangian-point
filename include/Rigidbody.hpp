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
    private:
        bool useGravity;
        Vector velocity;
        float mass;
        float bounciness;
        Vector extraForce;
    public:
        Rigidbody();
        virtual ~Rigidbody();
        
        /// \brief Set whether gravity affects this rigidbody
        void rbSetUseGravity(bool value);
        
        /// \brief Check whether gravity affects the rigidbody
        bool rbIsUsingGravity() const;
        
        /// \brief Set a mass value for the rigidbody
        void rbSetMass(float mass);
        
        /// \brief Get the mass of the rigidbody
        float rbGetMass() const;
        
        /// \brief Set a bounciness value for the rigidbody
        ///
        /// This is used on collision
        void rbSetBounciness(float bounciness);
        
        /// \brief Get the bounciness for the rigidbody
        float rbGetBounciness() const;
        
        /// \brief Set the current velocity for movement
        /// \param velocity the velocity in unit/s
        void rbSetVelocity(Vector velocity);
        
        /// \brief Get the current velocity
        Vector rbGetVelocity() const;
        
        /// \brief Set an extra force that would push the rigidbody
        ///
        /// This is designed for moving the rigidbody with force
        void rbSetExtraForce(Vector force);
        
        /// \brief Get the extra force
        Vector rbGetExtraForce() const;
        
        /// \brief Get the center of mass in global of the rigidbody
        virtual Vector rbGetCenter() const  = 0;
        
        /// \brief Move the rigidbody
        virtual void rbMove(float x, float y)  = 0;
        
        /// \brief Rotate the rigidbody
        virtual void rbSetRotation(float degree)  = 0;
    };
}
#endif /* Rigidbody_h */

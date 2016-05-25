//
//  GravitySource.h
//  LagrangianPoint
//
//  Created by Xiaxing SHI on 06/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#ifndef GravitySource_h
#define GravitySource_h

#include "Vector.hpp"

namespace physics {
    
    /// \brief The source of gracity, but it could be used as any single-point force
    class GravitySource {
    public:
        /// \brief Get the gravitational acceleration
        ///
        /// This represent a constant acceleration between a radius and a minimun distance, like the g = 9.8 m/s on Earth.
        /// Between the minimum and maximum distances, the real acceleration would be calculated by this value.
        ///
        /// \see https://en.wikipedia.org/wiki/Gravitational_acceleration
        virtual float getAcceleration() const = 0;
        
        /// \brief Get the center of mass for the gravity source
        virtual Vector getCenter() const = 0;
        
        /// \brief Get the radius for the gravity source, which could be seen as the radius of a planet
        virtual float getGravityRadius() const = 0;
        
        /// \brief Get the minimum distance begin with the center. This represent an area that still uses the constant acceleration
        virtual float getMinDistance() const = 0;
        
        /// \brief Get the maximum distance that the gravity can affect rigidbodies
        virtual float getMaxDistance() const = 0;
    };
}

#endif /* GravitySource_h */

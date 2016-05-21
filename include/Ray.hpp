//
//  Ray.hpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 21/05/16.
//
//

#ifndef Ray_h
#define Ray_h

#include "Vector.hpp"

namespace physics {
    class Ray {
    public:
        Vector origin;
        Vector direction;
        
        Ray(): Ray(Vector(), Vector()) {
            
        }
        
        Ray(Vector origin, Vector direction): origin(origin), direction(direction.normalize()) {
            
        }
    };
}

#endif /* Ray_h */

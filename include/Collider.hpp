//
//  Collider.hpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 21/05/16.
//
//

#ifndef Collider_h
#define Collider_h

#include <memory>
#include "Rigidbody.hpp"
#include "Ray.hpp"

namespace physics {
    class Collider {
        std::shared_ptr<physics::Rigidbody> attachedRigidbody;
        bool trigger;
    public:
        Collider();
        
        virtual bool raycast(Ray ray, float maxDistance) = 0;
        void setAttachedRigidbody(std::shared_ptr<physics::Rigidbody> rigidbody);
        std::shared_ptr<physics::Rigidbody> getAttachedRigidbody() const;
        void setTrigger(bool trigger);
        bool isTrigger() const;
        
    };
}

#endif /* Collider_h */

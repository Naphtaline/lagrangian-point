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
#include "RaycastHit.hpp"
#include "Vector.hpp"

namespace physics {
    class Collider {
        std::shared_ptr<Rigidbody> attachedRigidbody;
        bool trigger;
    public:
        Collider();
        virtual ~Collider();
        
        virtual bool raycast(Ray ray, float maxDistance, RaycastHit& hit) = 0;
        virtual Vector getRayOrigin() = 0;
        virtual float getRayDistance(const Vector &direction) = 0;
        
        void setAttachedRigidbody(std::shared_ptr<Rigidbody> rigidbody);
        std::shared_ptr<Rigidbody> getAttachedRigidbody() const;
        void setTrigger(bool trigger);
        bool isTrigger() const;
        
    };
}

#endif /* Collider_h */

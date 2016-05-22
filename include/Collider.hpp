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

namespace physics {
    class Collider : std::enable_shared_from_this<Collider> {
        std::shared_ptr<Rigidbody> attachedRigidbody;
        bool trigger;
    public:
        Collider();
        virtual ~Collider();
        
        virtual bool raycast(Ray ray, float maxDistance, RaycastHit& hit) = 0;
        void setAttachedRigidbody(std::shared_ptr<Rigidbody> rigidbody);
        std::shared_ptr<Rigidbody> getAttachedRigidbody() const;
        void setTrigger(bool trigger);
        bool isTrigger() const;
        
    };
}

#endif /* Collider_h */

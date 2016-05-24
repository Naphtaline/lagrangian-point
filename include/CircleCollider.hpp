//
//  CircleCollider.hpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 21/05/16.
//
//

#ifndef CircleCollider_h
#define CircleCollider_h

#include <memory>
#include "Vector.hpp"
#include "Collider.hpp"

namespace physics {
    class CircleCollider : public Collider {
    private:
        Vector center;
        float radius;
    public:
        CircleCollider();
        CircleCollider(Vector center, float radius);
        virtual ~CircleCollider();
        
        void setCenter(Vector center);
        
        Vector getCenter() const;
        
        void setRadius(float radius);
        
        /// \brief Get the radius for the collider
        float getRadius() const;
        
        virtual bool raycast(Ray ray, float maxDistance, RaycastHit& hit);
        virtual Vector getRayOrigin();
        virtual float getRayDistance(const Vector &direction);
    };
}


#endif /* CircleCollider_h */

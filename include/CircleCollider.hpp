//
//  CircleCollider.hpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 21/05/16.
//
//

#ifndef CircleCollider_h
#define CircleCollider_h

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
        void setCenter(Vector center);
        Vector getCenter() const;
        void setRadius(float radius);
        float getRadius() const;
        virtual bool raycast(Ray ray, float maxDistance);
    };
}


#endif /* CircleCollider_h */

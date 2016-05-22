//
//  RaycastHit.hpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 22/05/16.
//
//

#ifndef RaycastHit_h
#define RaycastHit_h

#include <memory>
#include "Collider.hpp"
#include "Vector.hpp"
#include "Rigidbody.hpp"

namespace physics {
    struct RaycastHit {
        float distance;
        Vector point;
        std::shared_ptr<Rigidbody> rigidbody;
    };
}

#endif /* RaycastHit_h */

//
//  Engine.hpp
//  LagrangianPoint
//
//  Created by Xiaxing SHI on 06/05/16.
//  Copyright © 2016 Dimgai. All rights reserved.
//

#ifndef Engine_h
#define Engine_h

#include <map>
#include <set>
#include <memory>
#include "Rigidbody.hpp"
#include "GravitySource.hpp"
#include "Collider.hpp"
#include "Clock.hpp"

namespace physics {
    
    /// \brief The singleton engine for the calculation of gravities
    class Engine {
    private:
        uint32_t nextHandle = 1;
        std::map<uint32_t, std::shared_ptr<Rigidbody>> rigidbodies;
        std::map<uint32_t, std::shared_ptr<GravitySource>> gravities;
        std::map<uint32_t, std::shared_ptr<Collider>> colliders;
        std::map<std::shared_ptr<Rigidbody>, std::set<std::shared_ptr<Collider>>> rigidColliders;
        float maxVelocity;
        int minX, minY, maxX, maxY;
        float bounceRateForMovementArea;
        std::shared_ptr<Clock> clock;
        
        Engine();
        ~Engine();

    public:
        /// \brief get the engine instance
        static Engine& get();
        
        // delete copy and move constructors and assign operators
        Engine(Engine const&) = delete;             // Copy construct
        Engine(Engine&&) = delete;                  // Move construct
        Engine& operator=(Engine const&) = delete;  // Copy assign
        Engine& operator=(Engine &&) = delete;      // Move assign
        
        /// \brief Add a rigidbody
        /// \return the handle for remove this rigidbody
        uint32_t addRigidbody(std::shared_ptr<Rigidbody> rigidbody);
        
        /// \brief Remove a rigidbody
        /// \param handleRigidbody the handle returned when the rigidbody was added
        void removeRigidbody(uint32_t handleRigidbody);
        
        /// \brief Add a gravity source
        /// \return the handle for remove this gravity source
        uint32_t addGravity(std::shared_ptr<GravitySource> gravity);
        
        /// \brief Remove a gravity source
        /// \param handleGravity the handle returned when the gravity source was added
        void removeGravity(uint32_t handleGravity);
        
        uint32_t addCollider(std::shared_ptr<Collider> collider);
        
        void removeCollider(uint32_t handleCollider);
        
        /// \brief Set a maximum velocity allowed by the engine. By Default, there is no limit (FLT_MAX)
        void setMaxVelocity(float v);
        
        /// \brief Set the area for possible movement
        void setMovementArea(int minX, int minY, int maxX, int maxY);
        
        /// \brief Set the bounce rate for the eadge of movement area
        void setBouncinessForMovementArea(float rate);
        
        /// \brief Calculate & update all rigidbodies in the engine
        /// \param clock A clock that would be reset in every update. This make the update frame rate independant
        void update();
    };
}

#endif /* Engine_h */

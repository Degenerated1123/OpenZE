#pragma once

#include <btBulletDynamicsCommon.h>
#include <BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h>

#include "utils/queue.h"
#include "utils/mathlib.h"

namespace Physics
{
    class Physics
    {
        friend class RigidBody;
    public:
        /**
         * @brief Physics
         */
        Physics(float gravity = -10.f);

        /**
         * @brief update
         * @param dt
         */
        void update(double dt);

        /**
         * @brief init
         */
        void init();

        void addRigidBody(btRigidBody *pRigidBody);
        void updateRigidBodies();

		/**
		 * @brief Shoots a simple trace through the physics-world
		 * @return Hitpoint
		 */
		Math::float3 rayTest(const Math::float3& start, const Math::float3& end);

        btDiscreteDynamicsWorld *world();
    private:
        btDbvtBroadphase m_Broadphase;
        btDefaultCollisionConfiguration m_CollisionConfiguration;
        btCollisionDispatcher m_Dispatcher;
        btSequentialImpulseConstraintSolver m_Solver;
        btDiscreteDynamicsWorld m_DynamicsWorld;

        Utils::Queue<btRigidBody *> m_RigidBodyQueue;
    };
}

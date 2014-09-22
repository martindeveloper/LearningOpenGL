//
//  TriangleEntity.h
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __OpenGl_OpenCL_Test__TriangleEntity__
#define __OpenGl_OpenCL_Test__TriangleEntity__

#include "Headers.h"
#include "Entity.h"
#include "Vector3.h"

namespace Game {

namespace Entities {
    class TriangleEntity : public Engine::Entity {
    private:
        Engine::Math::Vector3* Position;

    public:
        void virtual OnCreate();
        void virtual OnUpdate(int delta);
        void virtual OnDestroy();
    };
}
}

#endif /* defined(__OpenGl_OpenCL_Test__TriangleEntity__) */

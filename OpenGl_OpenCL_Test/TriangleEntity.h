//
//  TriangleEntity.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL__TriangleEntity__
#define __Learning_OpenGL__TriangleEntity__

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

#endif /* defined(__Learning_OpenGL__TriangleEntity__) */

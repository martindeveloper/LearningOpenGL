//
//  Entity.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL__Entity__
#define __Learning_OpenGL__Entity__

#include "Headers.h"
#include "Transform.h"

namespace Engine {
class Entity {
public:
    Engine::Components::Transform* Transform;

    Entity();
    ~Entity();
    void virtual OnCreate();
    void virtual OnUpdate(int delta);
    void virtual OnDraw(GLuint vertexBuffer);
    void virtual OnDestroy();
};
}

#endif /* defined(__Learning_OpenGL__Entity__) */

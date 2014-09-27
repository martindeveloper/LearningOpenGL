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
#include "Shader.h"

namespace Game {

namespace Entities {
    class TriangleEntity : public Engine::Entity {
    public:
        void virtual OnCreate();
        void virtual OnUpdate(int delta);
        void virtual OnDraw(GLuint vertexBuffer);
        void virtual OnDestroy();

    private:
        GLfloat VertexData[9] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        Engine::Shader* Shader;
    };
}
}

#endif /* defined(__Learning_OpenGL__TriangleEntity__) */

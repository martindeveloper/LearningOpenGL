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
#include "GLOptions.h"

namespace Game {

namespace Entities {
    class TriangleEntity : public Engine::Entity {
    public:
        void OnCreate() override;
        void OnUpdate(int delta) override;
        void OnDraw(Engine::GLOptions* options) override;
        void OnDestroy() override;

    private:
        GLfloat* VertexData;
        Engine::Shader* Shader;
        bool IsIncreasing = true;
    };
}
}

#endif /* defined(__Learning_OpenGL__TriangleEntity__) */

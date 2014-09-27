//
//  Transform.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 27.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL__Transform__
#define __Learning_OpenGL__Transform__

#include "Vector3.h"

namespace Engine {
namespace Components {
    class Transform {
    public:
        Transform();
        ~Transform();

    protected:
        Engine::Math::Vector3* Position;
        Engine::Math::Vector3* Scale;
        //TODO: Rotation Quaternion
    };
}
}

#endif /* defined(__Learning_OpenGL__Transform__) */

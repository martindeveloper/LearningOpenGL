//
//  Entity.h
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL__Entity__
#define __Learning_OpenGL__Entity__

namespace Engine {
class Entity {
public:
    void virtual OnCreate();
    void virtual OnUpdate(int delta);
    void virtual OnDestroy();
};
}

#endif /* defined(__Learning_OpenGL__Entity__) */

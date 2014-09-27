//
//  Vector3.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL__Vector3__
#define __Learning_OpenGL__Vector3__

namespace Engine {
namespace Math {
    struct Vector3 {
    public:
        Vector3();

        float X;
        float Y;
        float Z;
        Vector3 operator+(const float add);
    };
}
}

#endif /* defined(__Learning_OpenGL__Vector3__) */

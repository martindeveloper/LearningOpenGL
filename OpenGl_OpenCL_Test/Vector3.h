//
//  Vector3.h
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __OpenGl_OpenCL_Test__Vector3__
#define __OpenGl_OpenCL_Test__Vector3__

namespace Engine {
namespace Math {
    struct Vector3 {
        float X;
        float Y;
        float Z;

        Vector3 operator+(const float add);
    };
}
}

#endif /* defined(__OpenGl_OpenCL_Test__Vector3__) */

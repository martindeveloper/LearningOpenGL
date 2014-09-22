//
//  WindowOptions.h
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __OpenGl_OpenCL_Test__WindowOptions__
#define __OpenGl_OpenCL_Test__WindowOptions__

#include "Headers.h"

namespace Engine {
struct WindowOptions {
public:
    float Width;
    float Height;
    char* Title;
    uint32_t Flags = -1;

    ~WindowOptions();
};
}

#endif /* defined(__OpenGl_OpenCL_Test__WindowOptions__) */

//
//  WindowOptions.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL__WindowOptions__
#define __Learning_OpenGL__WindowOptions__

#include "Headers.h"

namespace Engine {
struct WindowOptions {
public:
    float Width;
    float Height;
    std::string* Title;
    uint32_t Flags = -1;

    ~WindowOptions();
};
}

#endif /* defined(__Learning_OpenGL__WindowOptions__) */

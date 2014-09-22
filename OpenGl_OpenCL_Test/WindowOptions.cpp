//
//  WindowOptions.cpp
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "WindowOptions.h"

Engine::WindowOptions::~WindowOptions()
{
    free(Title);
};
//
//  Vector3.cpp
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "Vector3.h"

using namespace Engine::Math;

Vector3 Vector3::operator+(const float add)
{
    Vector3 vec;

    vec.X = X + add;
    vec.Y = Y + add;
    vec.Z = Z + add;

    return vec;
};
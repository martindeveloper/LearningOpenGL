//
//  Transform.cpp
//  Learning_OpenGL
//
//  Created by Martin Pernica on 27.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "Transform.h"

using namespace Engine::Math;

Engine::Components::Transform::Transform()
{
    Position = new Vector3();
    Scale = new Vector3();
}

Engine::Components::Transform::~Transform()
{
    delete Position;
    delete Scale;
}
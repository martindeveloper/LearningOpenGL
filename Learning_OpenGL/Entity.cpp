//
//  Entity.cpp
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "Entity.h"

Engine::Entity::Entity()
{
    Transform = new Components::Transform();
}

Engine::Entity::~Entity()
{
    delete Transform;
}

void Engine::Entity::OnCreate()
{
}

void Engine::Entity::OnDestroy()
{
}

void Engine::Entity::OnUpdate(int delta)
{
}

void Engine::Entity::OnDraw(GLOptions* options)
{
}
//
//  TriangleEntity.cpp
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "TriangleEntity.h"

void Game::Entities::TriangleEntity::OnCreate()
{
    Position = new Engine::Math::Vector3();
    std::cout << "Creating" << std::endl;
};

void Game::Entities::TriangleEntity::OnDestroy()
{
    delete Position;
    std::cout << "Destroying" << std::endl;
};

void Game::Entities::TriangleEntity::OnUpdate(int delta)
{
    // TODO: Shaders
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0, 1, 0);
    glEnd();

    std::cout << "Updating with delta " << delta << std::endl;
};
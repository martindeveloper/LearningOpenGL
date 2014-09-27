//
//  TriangleEntity.cpp
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "TriangleEntity.h"

void Game::Entities::TriangleEntity::OnCreate()
{
    // TODO: Debug pipeline
    std::cout << "Creating TriangleEntity" << std::endl;

    VertexData[0] = -1.0f;
    VertexData[1] = -1.0f;
    VertexData[2] = 0.0f;

    VertexData[3] = 1.0f;
    VertexData[4] = -1.0f;
    VertexData[5] = 0.0f;

    VertexData[6] = 0.0f;
    VertexData[7] = 1.0f;
    VertexData[8] = 0.0f;

    Shader = new Engine::Shader("./Shaders/TriangleEntityVertex.glsl", "./Shaders/TriangleEntityFragment.glsl");
    Shader->DebugEnabled = true;
    Shader->Compile();
};

void Game::Entities::TriangleEntity::OnDestroy()
{
    std::cout << "Destroying TriangleEntity" << std::endl;
};

void Game::Entities::TriangleEntity::OnUpdate(int delta) {
    //std::cout << "Updating TriangleEntity with delta " << delta << std::endl;
};

void Game::Entities::TriangleEntity::OnDraw(GLuint vertexBuffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, NULL, sizeof(VertexData), &VertexData);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glUseProgram(Shader->GetProgramID());
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
};
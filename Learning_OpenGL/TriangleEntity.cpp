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

    VertexData = new GLfloat[9];

    VertexData[0] = -.2f;
    VertexData[1] = -.2f;
    VertexData[2] = 0.0f;

    VertexData[3] = .2f;
    VertexData[4] = -.2f;
    VertexData[5] = 0.0f;

    VertexData[6] = 0.0f;
    VertexData[7] = .2f;
    VertexData[8] = 0.0f;

    Shader = new Engine::Shader("./Shaders/TriangleEntityVertex.glsl", "./Shaders/TriangleEntityFragment.glsl");
    Shader->DebugEnabled = true;
    Shader->Compile();
};

void Game::Entities::TriangleEntity::OnDestroy()
{
    delete VertexData;

    std::cout << "Destroying TriangleEntity" << std::endl;
};

void Game::Entities::TriangleEntity::OnUpdate(int delta)
{
    //std::cout << "Updating TriangleEntity with delta " << delta << std::endl;

    // Resize on update
    float step = 1.005f;

    for (unsigned int index = 0; index < 9; index++) {
        if ((GLfloat)VertexData[index] > 1.8f && (GLfloat)VertexData[index] < 2.0f) {
            IsIncreasing = false;
        }

        if ((GLfloat)VertexData[index] < .2f && (GLfloat)VertexData[index] > .0f) {
            IsIncreasing = true;
        }

        if (IsIncreasing) {
            VertexData[index] *= step;
        } else {
            VertexData[index] /= step;
        }
    }
};

void Game::Entities::TriangleEntity::OnDraw(Engine::GLOptions* options)
{
    //TODO MVP
    glBindVertexArray(options->VertexArrayID);
    glBindBuffer(GL_ARRAY_BUFFER, options->VertexBuffer);

    glBufferSubData(GL_ARRAY_BUFFER, NULL, sizeof(GLfloat) * 9, VertexData);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, options->VertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glUseProgram(Shader->GetProgramID());
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
};
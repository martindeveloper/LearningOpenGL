//
//  main.cpp
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "Headers.h"
#include "WindowOptions.h"
#include "GameManager.h"
#include "ObjectsManager.h"
#include "Entity.h"
#include "TriangleEntity.h"

int main(int argc, char* argv[])
{
    //TODO use smart pointers
    Engine::WindowOptions* options = new Engine::WindowOptions();
    options->Width = 640;
    options->Height = 480;

    options->Title = new std::string("GL Learning");

    Engine::ObjectsManager* manager = new Engine::ObjectsManager();

    // Game entities
    Engine::Entity* triangle = new Game::Entities::TriangleEntity();

    manager->Add(triangle);

    Engine::GameManager* game = new Engine::GameManager();
    game->CreateWindowAndContext(options);
    game->CreateBuffers();
    game->SetObjectsManager(manager);
    game->StartUpdateLoop();

    delete game;

    return 0;
}
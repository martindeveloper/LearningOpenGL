//
//  main.cpp
//  OpenGl_OpenCL_Test
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

int main(int argc, const char* argv[])
{
    Engine::WindowOptions* options = new Engine::WindowOptions();
    options->Width = 640;
    options->Height = 480;

    //TODO: Refactor to std::string
    options->Title = "Testing";

    Engine::ObjectsManager* manager = new Engine::ObjectsManager();

    //entities
    Engine::Entity* triangle = new Game::Entities::TriangleEntity();

    manager->Add(triangle);

    Engine::GameManager* game = new Engine::GameManager();
    game->Initialize(options);
    game->SetObjectsManager(manager);
    game->StartUpdateLoop();

    delete game;

    return 0;
}

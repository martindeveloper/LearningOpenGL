//
//  SDL.cpp
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "GameManager.h"

Engine::GameManager::GameManager(void)
{
    LastError = new std::string("");
};

Engine::GameManager::~GameManager()
{
    SDL_Quit();

    delete Options;
    delete GameObjectsManager;
    delete LastError;
}

void Engine::GameManager::SetObjectsManager(Engine::ObjectsManager* manager)
{
    if (GameObjectsManager != NULL) {
        delete GameObjectsManager;
    }

    GameObjectsManager = manager;
}

void Engine::GameManager::WriteError(char* extra = NULL)
{
    delete LastError;

    if (extra == NULL) {
        LastError->assign(SDL_GetError());
        return;
    }

    LastError = new std::string(extra);
    LastError->append(" ");
    LastError->append(SDL_GetError());
}

bool Engine::GameManager::CreateWindowAndContext(WindowOptions* options)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        WriteError();

        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    if (options->Flags == -1) {
        options->Flags = SDL_WINDOW_OPENGL;
    }

    Window = SDL_CreateWindow(options->Title->c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, options->Width,
                              options->Height, options->Flags);

    if (Window == NULL) {
        WriteError();

        return false;
    }

    Context = SDL_GL_CreateContext(Window);

    return true;
};

void Engine::GameManager::StartUpdateLoop()
{
    IsUpdateKillPending = false;

    while (!IsUpdateKillPending) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_KEYDOWN:
                // TODO: Input system
                break;
            case SDL_QUIT:
                IsUpdateKillPending = true;
                break;
            }
        }

        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        TimeNow = SDL_GetTicks();
        int delta = TimeNow - TimePast;

        if (TimePast == 0) {
            delta = 1;
        }

        TimePast = TimeNow;

        GameObjectsManager->DispatchUpdateEvent(delta);

        SDL_GL_SwapWindow(Window);
    }
}

void Engine::GameManager::StopUpdateLoop()
{
    IsUpdateKillPending = true;
}
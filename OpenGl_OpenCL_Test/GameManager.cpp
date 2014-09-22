//
//  SDL.cpp
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "GameManager.h"

Engine::GameManager::GameManager(void) { LastError = (char*)malloc(sizeof(char)); };

Engine::GameManager::~GameManager()
{
    SDL_Quit();

    delete Options;
    delete GameObjectsManager;

    free(LastError);
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
    if (strlen(LastError) != 0) {
        free(LastError);
    }

    if (extra == NULL) {
        strcpy(LastError, SDL_GetError());
        return;
    }

    const char* sdlError = SDL_GetError();
    char* temp = (char*)malloc(strlen(sdlError) + strlen(extra) + 1);

    if (temp != NULL) {
        strcpy(temp, sdlError);
        strcat(temp, extra);
    }

    LastError = temp;
}

bool Engine::GameManager::Initialize(WindowOptions* options)
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

    Window = SDL_CreateWindow(options->Title, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, options->Width,
                              options->Height, options->Flags);

    if (Window == NULL) {
    }

    Context = SDL_GL_CreateContext(Window);

    return true;
};

void Engine::GameManager::StartUpdateLoop()
{
    while (!IsUpdateKillPending) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_KEYDOWN:
                //Input system
                break;
            case SDL_QUIT:
                IsUpdateKillPending = true;
                break;
            }
        }

        glClearColor(255.0f, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        TimeNow = SDL_GetTicks();
        int delta = TimeNow - TimePast;
        TimePast = TimeNow;

        GameObjectsManager->DispatchUpdateEvent(delta);

        SDL_GL_SwapWindow(Window);
    }
}

void Engine::GameManager::StopUpdateLoop()
{
    IsUpdateKillPending = true;
}
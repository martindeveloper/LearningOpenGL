//
//  SDL.h
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef OpenGl_OpenCL_Test_SDL_h
#define OpenGl_OpenCL_Test_SDL_h

#include "Headers.h"
#include "ObjectsManager.h"
#include "WindowOptions.h"

namespace Engine {
class GameManager {
private:
    WindowOptions* Options;
    SDL_Window* Window;
    SDL_GLContext Context;
    ObjectsManager* GameObjectsManager = NULL;
    char* LastError;

    void WriteError(char* extra);
    bool IsUpdateKillPending = false;

    int TimeNow;
    int TimePast;

public:
    GameManager();
    ~GameManager();

    bool Initialize(WindowOptions* options);
    void StartUpdateLoop();
    void StopUpdateLoop();
    void SetObjectsManager(ObjectsManager* manager);
};
}
#endif

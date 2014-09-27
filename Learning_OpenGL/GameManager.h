//
//  SDL.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL_GameManager_h__
#define __Learning_OpenGL_GameManager_h__

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
    std::string* LastError;

    //Buffers
    const float VertexBufferSize = 128 * 1000 * 1000;
    GLuint VertexBuffer = 0;
    GLuint VertexArrayID;

    void WriteError(char* extra);
    bool IsUpdateKillPending = false;

    int TimeNow = 0;
    int TimePast = 0;

public:
    GameManager();
    ~GameManager();

    bool CreateWindowAndContext(WindowOptions* options);
    void CreateBuffers();
    void StartUpdateLoop();
    void StopUpdateLoop();
    void SetObjectsManager(ObjectsManager* manager);
};
}
#endif

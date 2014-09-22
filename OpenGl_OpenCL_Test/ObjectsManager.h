//
//  GameObjectsManager.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __Learning_OpenGL__GameObjectsManager__
#define __Learning_OpenGL__GameObjectsManager__

#include "Headers.h"
#include "Entity.h"

namespace Engine {
class ObjectsManager {
private:
    std::vector<Entity*>* List;

public:
    ObjectsManager();
    ~ObjectsManager();
    void Add(Entity* entity);
    void RemoveAll();
    void DispatchUpdateEvent(int delta);
};
}

#endif /* defined(__Learning_OpenGL__GameObjectsManager__) */

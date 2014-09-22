//
//  GameObjectsManager.h
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#ifndef __OpenGl_OpenCL_Test__GameObjectsManager__
#define __OpenGl_OpenCL_Test__GameObjectsManager__

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

#endif /* defined(__OpenGl_OpenCL_Test__GameObjectsManager__) */

//
//  GameObjectsManager.cpp
//  OpenGl_OpenCL_Test
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#include "ObjectsManager.h"

Engine::ObjectsManager::~ObjectsManager()
{
    RemoveAll();
    delete List;
};

Engine::ObjectsManager::ObjectsManager()
{
    List = new std::vector<Entity*>();
};

void Engine::ObjectsManager::Add(Entity* entity)
{
    entity->OnCreate();
    List->push_back(entity);
};

void Engine::ObjectsManager::RemoveAll()
{
    for (int i = 0; i < List->size(); i++) {
        Entity* entity = List->at(i);
        entity->OnDestroy();

        delete entity;
    }

    List->clear();
};

void Engine::ObjectsManager::DispatchUpdateEvent(int delta)
{
    for (int i = 0; i < List->size(); i++) {
        Entity* entity = List->at(i);
        entity->OnUpdate(delta);
    }
};
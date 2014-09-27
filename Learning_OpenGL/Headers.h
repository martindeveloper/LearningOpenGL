//
//  Headers.h
//  Learning_OpenGL
//
//  Created by Martin Pernica on 22.09.14.
//  Copyright (c) 2014 Martin Pernica. All rights reserved.
//

#pragma once
#ifndef __Learning_OpenGL_Headers_h__
#define __Learning_OpenGL_Headers_h__

#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#include <SDL.h>
#include <SDL_opengl.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#endif

#endif
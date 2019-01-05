//
//  GameEngine.cpp
//  GameEngine
//
//  Created by Yvo Keuter on 9/6/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#include <SDL2/SDL.h>
#include <OpenGL/gl3.h>

#include "GameEngine.h"

namespace GameEngine {
    
    int init() {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        
        return 0;
    }
    
}

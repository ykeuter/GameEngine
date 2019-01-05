//
//  Window.cpp
//  GameEngine
//
//  Created by Yvo Keuter on 9/6/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#include "Window.h"
#include "GameEngineErrors.h"

namespace GameEngine {
    
    Window::Window()
    {
    }
    
    
    Window::~Window()
    {
    }
    
    int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {
        
        Uint32 flags = SDL_WINDOW_OPENGL;
        _screenWidth = screenWidth;
        _screenHeight = screenHeight;
        
        if (currentFlags & INVISIBLE) {
            flags |= SDL_WINDOW_HIDDEN;
        }
        if (currentFlags & FULLSCREEN) {
            flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        }
        if (currentFlags & BORDERLESS) {
            flags |= SDL_WINDOW_BORDERLESS;
        }
        
        _sdlWindow = SDL_CreateWindow(windowName.c_str(),
                                   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   screenWidth, screenHeight, flags);
        if (_sdlWindow == nullptr) {
            fatalError("SDL Window could not be created!");
        }
        
        SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
        
        if (glContext == nullptr) {
            fatalError("SDL_GL context could not be created!");
        }
        
        /*GLuint vertexArrayID;
        glGenVertexArrays(1, &vertexArrayID);
        glBindVertexArray(vertexArrayID);*/
        
        //Check the OpenGL version
        std::printf("***   OpenGL Version: %s   ***\n", glGetString(GL_VERSION));
        
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        
        //Set VSYNC
        SDL_GL_SetSwapInterval(0);
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        return 0;
    }
    
    void Window::swapBuffer() {
        SDL_GL_SwapWindow(_sdlWindow);
    }
    
}

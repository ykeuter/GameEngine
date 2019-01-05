//
//  Window.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/6/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__Window__
#define __GameEngine__Window__

#include <SDL2/SDL.h>
#include <OpenGL/gl3.h>
#include <string>

namespace GameEngine {
    
    enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };
    
    class Window
    {
    public:
        Window();
        ~Window();
        
        int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
        
        void swapBuffer();
        
        int getScreenWidth() { return _screenWidth; }
        int getScreenHeight() { return _screenHeight; }
    private:
        SDL_Window* _sdlWindow;
        int _screenWidth, _screenHeight;
    };
    
}

#endif /* defined(__GameEngine__Window__) */

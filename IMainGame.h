//
//  IMainGame.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/23/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__IMainGame__
#define __GameEngine__IMainGame__

#include "GameEngine.h"
#include "Window.h"
#include <memory>
#include "InputManager.h"
#include "ScreenList.h"

namespace GameEngine {
    
    class ScreenList;
    class IGameScreen;
    
    class IMainGame {
    public:
        IMainGame();
        virtual ~IMainGame();
        
        // Runs and initializes the game
        void run();
        // Exits the game
        void exitGame();
        
        // Called on initialization
        virtual void onInit() = 0;
        // For adding all screens
        virtual void addScreens() = 0;
        // Called when exiting
        virtual void onExit() = 0;
        
        void onSDLEvent(SDL_Event& evnt);
        
        const float getFps() const {
            return m_fps;
        }
        
        InputManager inputManager;
        
    protected:
        bool init();
        bool initSystems();
        
        // Custom update function
        virtual void update();
        // Custom render function
        virtual void draw();
        
        std::unique_ptr<ScreenList> m_screenList = nullptr;
        IGameScreen* m_currentScreen = nullptr;
        bool m_isRunning = false;
        float m_fps = 0.0f;
        Window m_window;
    };
    
}

#endif /* defined(__GameEngine__IMainGame__) */

//
//  ScreenList.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/23/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__ScreenList__
#define __GameEngine__ScreenList__

#include <vector>

namespace GameEngine {
    
    class IMainGame;
    class IGameScreen;
    
    class ScreenList {
    public:
        ScreenList(IMainGame* game);
        ~ScreenList();
        
        IGameScreen* moveNext();
        IGameScreen* movePrevious();
        
        void setScreen(int nextScreen);
        void addScreen(IGameScreen* newScreen);
        
        void destroy();
        
        IGameScreen* getCurrent();
        
    protected:
        IMainGame* m_game = nullptr;
        std::vector<IGameScreen*> m_screens;
        int m_currentScreenIndex = -1;
    };
    
}

#endif /* defined(__GameEngine__ScreenList__) */

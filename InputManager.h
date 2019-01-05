//
//  InputManager.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/9/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__InputManager__
#define __GameEngine__InputManager__

#include <unordered_map>
#include <glm/glm.hpp>

namespace GameEngine {
    
    // Input manager stores a key map that maps SDL_Keys to booleans.
    // If the value in the key map is true, then the key is pressed.
    // Otherwise, it is released.
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();
        
        void update();
        
        void pressKey(unsigned int keyID);
        void releaseKey(unsigned int keyID);
        
        void setMouseCoords(float x, float y);
        
        bool isKeyPressed(unsigned int keyID);
        
        bool isKeyDown(unsigned int keyID);
        
        glm::vec2 getMouseCoords() const { return _mouseCoords; }
    private:
        bool wasKeyDown(unsigned int keyID);
        
        std::unordered_map<unsigned int, bool> _keyMap;
        std::unordered_map<unsigned int, bool> _previousKeyMap;
        glm::vec2 _mouseCoords;
    };
    
}

#endif /* defined(__GameEngine__InputManager__) */

//
//  Timing.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/9/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__Timing__
#define __GameEngine__Timing__

namespace GameEngine {
    
    ///Calculates FPS and also limits FPS
    class FpsLimiter {
    public:
        FpsLimiter();
        
        // Initializes the FPS limiter. For now, this is
        // analogous to setMaxFPS
        void init(float maxFPS);
        
        // Sets the desired max FPS
        void setMaxFPS(float maxFPS);
        
        void begin();
        
        // end() will return the current FPS as a float
        float end();
    private:
        // Calculates the current FPS
        void calculateFPS();
        
        // Variables
        float _fps;
        float _maxFPS;
        float _frameTime;
        unsigned int _startTicks;
    };
    
}

#endif /* defined(__GameEngine__Timing__) */

//
//  ParticleEngine2D.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/18/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__ParticleEngine2D__
#define __GameEngine__ParticleEngine2D__

#include <vector>

namespace GameEngine {
    
    class ParticleBatch2D;
    class SpriteBatch;
    
    class ParticleEngine2D {
    public:
        ParticleEngine2D();
        ~ParticleEngine2D();
        
        // After adding a particle batch, the ParticleEngine2D becomes
        // responsible for deallocation.
        void addParticleBatch(ParticleBatch2D* particleBatch);
        
        void update(float deltaTime);
        
        void draw(SpriteBatch* spriteBatch);
        
    private:
        std::vector<ParticleBatch2D*> m_batches;
    };
    
}

#endif /* defined(__GameEngine__ParticleEngine2D__) */

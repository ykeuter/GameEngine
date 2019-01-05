//
//  ParticleBatch2D.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/18/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__ParticleBatch2D__
#define __GameEngine__ParticleBatch2D__

#include <glm/glm.hpp>
#include "Vertex.h"
#include "SpriteBatch.h"
#include "GLTexture.h"
#include <functional>

namespace GameEngine {
    
    class Particle2D {
    public:
        glm::vec2 position = glm::vec2(0.0f);
        glm::vec2 velocity = glm::vec2(0.0f);
        ColorRGBA8 color;
        float life = 0.0f;
        float width = 0.0f;
    };
    
    // Default function pointer
    inline void defaultParticleUpdate(Particle2D& particle, float deltaTime) {
        particle.position += particle.velocity * deltaTime;
    }
    
    class ParticleBatch2D {
    public:
        ParticleBatch2D();
        ~ParticleBatch2D();
        
        void init(int maxParticles,
                  float decayRate,
                  GLTexture texture,
                  std::function<void(Particle2D&, float)> updateFunc = defaultParticleUpdate);
        
        void update(float deltaTime);
        
        void draw(SpriteBatch* spriteBatch);
        
        void addParticle(const glm::vec2& position,
                         const glm::vec2& velocity,
                         const ColorRGBA8& color,
                         float width);
        
    private:
        int findFreeParticle();
        std::function<void(Particle2D&, float)> m_updateFunc; ///< Function pointer for custom updates
        
        float m_decayRate = 0.1f;
        Particle2D* m_particles = nullptr;
        int m_maxParticles = 0;
        int m_lastFreeParticle = 0;
        GLTexture m_texture;
    };
    
}

#endif /* defined(__GameEngine__ParticleBatch2D__) */

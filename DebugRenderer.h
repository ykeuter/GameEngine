//
//  DebugRenderer.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/28/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__DebugRenderer__
#define __GameEngine__DebugRenderer__

#include "GLSLProgram.h"
#include "Vertex.h"
#include <glm/glm.hpp>
#include <vector>

namespace GameEngine {
    class DebugRenderer {
    public:
        DebugRenderer();
        ~DebugRenderer();
        
        void init();
        void end();
        void drawBox(const glm::vec4& destRect, const ColorRGBA8& color, float angle);
        void drawCircle(const glm::vec2& center, const ColorRGBA8& color, float radius);
        void render(const glm::mat4& projectionMatrix, float lineWidth);
        void dispose();
        
        struct DebugVertex {
            glm::vec2 position;
            GameEngine::ColorRGBA8 color;
        };
    private:
        GameEngine::GLSLProgram m_program;
        std::vector<DebugVertex> m_verts;
        std::vector<GLuint> m_indices;
        GLuint m_vbo = 0, m_vao = 0, m_ibo = 0;
        int m_numElements = 0;
    };
    
}

#endif /* defined(__GameEngine__DebugRenderer__) */

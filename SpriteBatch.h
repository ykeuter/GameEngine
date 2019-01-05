//
//  SpriteBatch.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/7/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__SpriteBatch__
#define __GameEngine__SpriteBatch__

#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"

namespace GameEngine{
    
    enum class GlyphSortType {
        NONE,
        FRONT_TO_BACK,
        BACK_TO_FRONT,
        TEXTURE
    };
    
    class Glyph {
    public:
        Glyph() {}
        Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, float Depth, const ColorRGBA8& color);
        Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, float Depth, const ColorRGBA8& color, float angle);
        
        
        GLuint texture;
        float depth;
        
        Vertex topLeft;
        Vertex bottomLeft;
        Vertex topRight;
        Vertex bottomRight;
    private:
        // Rotates a point about (0,0) by angle
        glm::vec2 rotatePoint(const glm::vec2& pos, float angle);
    };
    
    class RenderBatch {
    public:
        RenderBatch(GLuint Offset, GLuint NumVertices, GLuint Texture) : offset(Offset),
        numVertices(NumVertices), texture(Texture) {
        }
        GLuint offset;
        GLuint numVertices;
        GLuint texture;
    };
    
    class SpriteBatch
    {
    public:
        SpriteBatch();
        ~SpriteBatch();
        
        void init();
        
        void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
        void end();
        
        // Adds a glyph to the spritebatch
        void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const ColorRGBA8& color);
        // Adds a glyph to the spritebatch with rotation
        void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const ColorRGBA8& color,
                  float angle);
        // Adds a glyph to the spritebatch with rotation
        void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const ColorRGBA8& color,
                  const glm::vec2& dir);
        
        void renderBatch();
        
    private:
        void createRenderBatches();
        void createVertexArray();
        void sortGlyphs();
        
        static bool compareFrontToBack(Glyph* a, Glyph* b);
        static bool compareBackToFront(Glyph* a, Glyph* b);
        static bool compareTexture(Glyph* a, Glyph* b);
        
        GLuint _vbo;
        GLuint _vao;
        
        GlyphSortType _sortType;
        
        std::vector<Glyph*> _glyphPointers; ///< This is for sorting
        std::vector<Glyph> _glyphs; ///< These are the actual glyphs
        std::vector<RenderBatch> _renderBatches;
    };
    
}
#endif /* defined(__GameEngine__SpriteBatch__) */

//
//  TileSheet.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/28/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__TileSheet__
#define __GameEngine__TileSheet__

#include "GLTexture.h"
#include <glm/glm.hpp>

namespace GameEngine {
    class TileSheet {
    public:
        void init(const GLTexture& texture, const glm::ivec2& tileDims) {
            this->texture = texture;
            this->dims = tileDims;
        }
        
        glm::vec4 getUVs(int index) {
            int xTile = index % dims.x;
            int yTile = index / dims.x;
            
            glm::vec4 uvs;
            uvs.x = xTile / (float)dims.x;
            uvs.y = yTile / (float)dims.y;
            uvs.z = 1.0f / dims.x;
            uvs.w = 1.0f / dims.y;
            
            return uvs;
        }
        
        GLTexture texture;
        glm::ivec2 dims;
    };
}

#endif /* defined(__GameEngine__TileSheet__) */

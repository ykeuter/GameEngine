//
//  TextureCache.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/5/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__TextureCache__
#define __GraphicsTutorials__TextureCache__

#include <map>
#include "GLTexture.h"

namespace GameEngine {
//This caches the textures so that multiple sprites can use the same textures
class TextureCache
{
public:
    TextureCache();
    ~TextureCache();
    
    GLTexture getTexture(std::string texturePath);
    
private:
    std::map<std::string, GLTexture> _textureMap;
};
}
#endif /* defined(__GraphicsTutorials__TextureCache__) */

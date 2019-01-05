//
//  ResourceManager.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/5/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__ResourceManager__
#define __GraphicsTutorials__ResourceManager__

#include "TextureCache.h"
#include <string>

namespace GameEngine {
//This is a way for us to access all our resources, such as
//Models or textures.
class ResourceManager
{
public:
    static GLTexture getTexture(std::string texturePath);
    
private:
    static TextureCache _textureCache;
    
};
}
#endif /* defined(__GraphicsTutorials__ResourceManager__) */

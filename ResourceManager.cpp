//
//  ResourceManager.cpp
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/5/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#include "ResourceManager.h"

namespace GameEngine {
TextureCache ResourceManager::_textureCache;

GLTexture ResourceManager::getTexture(std::string texturePath) {
    return _textureCache.getTexture(texturePath);
}
}

//
//  ImageLoader.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/4/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__ImageLoader__
#define __GraphicsTutorials__ImageLoader__

#include "GLTexture.h"
#include <string>

namespace GameEngine {
//Loads images into GLTextures
class ImageLoader
{
public:
    static GLTexture loadPNG(std::string filePath);
};
}

#endif /* defined(__GraphicsTutorials__ImageLoader__) */

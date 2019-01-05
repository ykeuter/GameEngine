//
//  Sprite.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/3/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__Sprite__
#define __GraphicsTutorials__Sprite__

#include <OpenGL/gl3.h>
#include "GLTexture.h"
#include <string>

namespace GameEngine {
class Sprite
{
public:
    Sprite();
    ~Sprite();
    
    void init(float x, float y, float width, float height, std::string texturePath);
    
    void draw();
    
private:
    float _x;
    float _y;
    float _width;
    float _height;
    GLuint _vboID;
    GLTexture _texture;
    
};
}
#endif /* defined(__GraphicsTutorials__Sprite__) */

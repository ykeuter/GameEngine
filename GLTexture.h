//
//  GLTexture.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/4/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__GLTexture__
#define __GraphicsTutorials__GLTexture__

#include <OpenGL/gl3.h>
namespace GameEngine {
struct GLTexture {
    GLuint id;
    int width;
    int height;
};
}
#endif /* defined(__GraphicsTutorials__GLTexture__) */

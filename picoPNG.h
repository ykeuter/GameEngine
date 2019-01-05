//
//  picoPNG.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/4/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__picoPNG__
#define __GraphicsTutorials__picoPNG__

#include <vector>

namespace GameEngine {
extern int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, unsigned long& image_height, const unsigned char* in_png, size_t in_size, bool convert_to_rgba32 = true);
}
#endif /* defined(__GraphicsTutorials__picoPNG__) */

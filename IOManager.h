//
//  IOManager.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/4/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__IOManager__
#define __GraphicsTutorials__IOManager__

#include <vector>

namespace GameEngine {
class IOManager {
public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
    static bool readFileToBuffer(std::string filePath, std::string& buffer);
};
}
#endif /* defined(__GraphicsTutorials__IOManager__) */

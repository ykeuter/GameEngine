//
//  GameEngineErrors.cpp
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/3/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

namespace GameEngine {
//Prints out an error message and exits the game
void fatalError(std::string errorString) {
    std::cout << errorString << std::endl;
    std::cout << "Enter any key to quit...";
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
    exit(1);
}
}
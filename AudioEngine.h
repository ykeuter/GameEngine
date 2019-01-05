//
//  AudioEngine.h
//  GameEngine
//
//  Created by Yvo Keuter on 9/15/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GameEngine__AudioEngine__
#define __GameEngine__AudioEngine__

#include <SDL2_mixer/SDL_mixer.h>
#include <string>
#include <map>

namespace GameEngine {
    
    class SoundEffect {
    public:
        friend class AudioEngine;
        
        /// Plays the effect file
        /// @param loops: If loops == -1, loop forever,
        /// otherwise play it loops+1 times
        void play(int loops = 0);
    private:
        Mix_Chunk* m_chunk = nullptr;
    };
    
    class Music {
    public:
        friend class AudioEngine;
        
        /// Plays the music file
        /// @param loops: If loops == -1, loop forever,
        /// otherwise play it loops times
        void play(int loops = 1);
        
        /// Pauses whatever song is currently playing
        static void pause();
        /// Stops whatever song is currently playing
        static void stop();
        /// Resumes whatever song is currently playing
        static void resume();
    private:
        Mix_Music* m_music = nullptr;
    };
    
    class AudioEngine {
    public:
        AudioEngine();
        ~AudioEngine();
        
        void init();
        void destroy();
        
        SoundEffect loadSoundEffect(const std::string& filePath);
        Music loadMusic(const std::string& filePath);
    private:
        
        std::map<std::string, Mix_Chunk*> m_effectMap; ///< Effects cache
        std::map<std::string, Mix_Music*> m_musicMap; ///< Music cache
        
        bool m_isInitialized = false;
    };
    
}

#endif /* defined(__GameEngine__AudioEngine__) */

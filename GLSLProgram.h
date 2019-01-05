//
//  GLSLProgram.h
//  GraphicsTutorials
//
//  Created by Yvo Keuter on 9/3/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __GraphicsTutorials__GLSLProgram__
#define __GraphicsTutorials__GLSLProgram__

#include <string>
#include <OpenGL/gl3.h>

namespace GameEngine {
//This class handles the compilation, linking, and usage of a GLSL shader program.
//Reference: http://www.opengl.org/wiki/Shader_Compilation
class GLSLProgram
{
public:
    GLSLProgram();
    ~GLSLProgram();
    
    void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath);
    
    void compileShadersFromSource(const char* vertexSource, const char* fragmentSource);
    
    void linkShaders();
    
    GLint getUniformLocation(const std::string& uniformName);
    
    void addAttribute(const std::string& attributeName);
    
    void use();
    void unuse();
    
    void dispose();
private:
    
    int _numAttributes;
    
    void compileShader(const char* source, const std::string& name, GLuint id);
    
    GLuint _programID;
    GLuint _vertexShaderID;
    GLuint _fragmentShaderID;
    
};
}
#endif /* defined(__GraphicsTutorials__GLSLProgram__) */

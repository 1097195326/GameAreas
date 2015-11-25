//
//  RenderingEngine2.cpp
//  TestOpengles
//
//  Created by 张洪星 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#include "IRenderingEngine.h"
#include <iostream>
#include <OpenGLES/ES2/gl.h>
//#include <OpenGLES/ES2/glext.h>


class RenderingEngine2 : public IRenderingEngine
{
public:
    RenderingEngine2();
    void    initialize(int width, int height);
    void    render() const;
    void    updateAnimation(float timeStep);
    
private:
    GLuint  buildShader(const char * source, GLenum type) const;
    GLuint  buildProgram(const char * vShader, const char * fShader) const;
    GLuint  m_renderBuffer;
    GLuint  m_frameBuffer;
    GLuint  m_simpleProgram;
    
};
IRenderingEngine * CreateRenderer2()
{
    return new RenderingEngine2();
}

RenderingEngine2::RenderingEngine2()
{
    
}
void RenderingEngine2::initialize(int width, int height)
{
    
}
void RenderingEngine2::render()const
{
    
}
void RenderingEngine2::updateAnimation(float timeStep)
{
    
}
GLuint RenderingEngine2::buildShader(const char *source, GLenum type) const
{
    GLuint shaderHandler = glCreateShader(type);
    glShaderSource(shaderHandler, 1, &source, 0);
    glCompileShader(shaderHandler);
    
    GLint compileSuccess;
    glGetShaderiv(shaderHandler, GL_COMPILE_STATUS, &compileSuccess);
    
    if (compileSuccess == GL_FALSE)
    {
        GLchar message[256];
        glGetShaderInfoLog(shaderHandler, sizeof(message), 0, &message[0]);
        std::cout<<message;
        exit(1);
    }
    
    return shaderHandler;
}
GLuint RenderingEngine2::buildProgram(const char *vShader, const char *fShader) const
{
    GLuint vertexShader = buildShader(vShader, GL_VERTEX_SHADER);
    GLuint fragmentShader = buildShader(fShader, GL_FRAGMENT_SHADER);

    GLuint programHander = glCreateProgram();
    glAttachShader(programHander, vertexShader);
    glAttachShader(programHander, fragmentShader);
    
    glLinkProgram(programHander);
    
    GLint programSuccess;
    glGetProgramiv(programHander, GL_LINK_STATUS, &programSuccess);
    
    if (programSuccess == GL_FALSE)
    {
        GLchar message[256];
        glGetProgramInfoLog(programHander, sizeof(message), 0, &message[0]);
        std::cout<<message;
        
        exit(1);
    }
    
    return programHander;
}
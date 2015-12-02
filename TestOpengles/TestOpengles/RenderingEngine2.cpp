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
#include <cmath>
//#include <OpenGLES/ES2/glext.h>

#define STRINGIFY(x) #x
#include "Shaders/Simple.vert"
#include "Shaders/Simple.frag"

#include "SocketClient.hpp"
#include "SocketServer.hpp"


class RenderingEngine2 : public IRenderingEngine
{
public:
    RenderingEngine2();
    void    initialize(int width, int height);
    void    render() const;
    void    updateAnimation(float timeStep);
    
private:
    void    playOrtho(float maxX, float maxY);
    void    playRotation(float degrees);
    
    GLuint  buildShader(const char * source, GLenum type) const;
    GLuint  buildProgram(const char * vShader, const char * fShader) const;
    GLuint  m_renderBuffer;
    GLuint  m_frameBuffer;
    GLuint  m_simpleProgram;
    
    //
    SocketClient * clientSocket;
    SocketServer * serverSocket;
    
};
IRenderingEngine * CreateRenderer2()
{
    return new RenderingEngine2();
}
struct Vertex{
    float Position[2];
    float Color[4];
};
const Vertex Verteces[] =
{
    {{0.5,-0.8},{1,1,0.5,1}},
    {{-0.5,-0.8},{1,1,0.5,1}},
    {{0,1},{1,1,0.5,1}},
    {{0.5,-0.8},{0.5,0.5,0.5}},
    {{-0.5,-0.8},{0.5,0.5,0.5}},
    {{0,-0.4},{0.5,0.5,0.5}},
};

RenderingEngine2::RenderingEngine2()
{
    glGenRenderbuffers(1, &m_renderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
}
void RenderingEngine2::initialize(int width, int height)
{
//    printf("while ----");
    serverSocket = new SocketServer();
//    clientSocket = new SocketClient();
    
//    glGenFramebuffers(1, &m_frameBuffer);
//    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
//    
//    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
//                              GL_COLOR_ATTACHMENT0,
//                              GL_RENDERBUFFER,
//                              m_renderBuffer);
//    
//    glViewport(0, 0, width, height);
//    
//    m_simpleProgram = buildProgram(SimpleVertexShader, SimpleFragmentShader);
//    glUseProgram(m_simpleProgram);
    
    
    
}
void RenderingEngine2::playOrtho(float maxX, float maxY)
{
    float a = 1.0f / maxX;
    float b = 1.0f / maxY;
    float ortho[16] =
    {
        a,  0,  0,  0,
        0,  b,  1,  0,
        0,  0,  -1, 0,
        0,  0,  0,  1
    };
    GLint projectionUniform = glGetUniformLocation(m_simpleProgram, "Projection");
    glUniformMatrix4fv(projectionUniform,1,0,ortho);
    
}
void RenderingEngine2::playRotation(float degrees)
{
    float radians = degrees * 3.14159f / 180.0f;
    float s = std::sin(radians);
    float c = std::cos(radians);
    
    float modelView[16] =
    {
        c,  s,  0,  0,
        s,  c,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    };
    GLint modelViewUniform = glGetUniformLocation(m_simpleProgram, "ModelView");
    glUniformMatrix4fv(modelViewUniform, 1, 0, modelView);
}
void RenderingEngine2::render()const
{
    serverSocket->run();
//    clientSocket->run();
    
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
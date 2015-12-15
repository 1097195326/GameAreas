//
//  RenderingEngine2.cpp
//  TestOpengles
//
//  Created by 张洪星 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#include "RenderingEngine2.h"

#include <iostream>
#include <cmath>


#define STRINGIFY(x) #x
#include "Shaders/Simple.vert"
#include "Shaders/Simple.frag"

//#include "SocketClient.hpp"
//#include "SocketServer.hpp"

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
    {{100,0},    {1,1,0.5f,1}},
    {{-100,0},   {1,1,0.5f,1}},
    {{0,320},         {1,1,0.5f,1}},
    {{100,0},    {0.5f,0.5f,0.5f}},
    {{-100,0},   {0.5f,0.5f,0.5f}},
    {{0,0},      {0.5f,0.5f,0.5f}},
};

RenderingEngine2::RenderingEngine2()
{
//    m_renderBuffer;
//    m_frameBuffer;
    glGenRenderbuffers(1, &m_renderBuffer);
    if (m_renderBuffer == GL_FALSE)
    {
        printf("m_renderBuffer faild :%d\n",m_renderBuffer);
        return;
    }else
    {
        printf("m_renderBuffer success:%d\n",m_renderBuffer);
    }
    glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
}
void RenderingEngine2::initialize(int width, int height)
{
//    printf("while ----");
//    serverSocket = new SocketServer();
//    clientSocket = new SocketClient();
    
    printf("width:%d\n",width);
    printf("height:%d\n",height);
    
    glGenFramebuffers(1, &m_frameBuffer);
    if (m_frameBuffer == GL_FALSE)
    {
        printf("m_frameBuffer faild :%d\n",m_frameBuffer);
        return;
    }else
    {
        printf("m_frameBuffer success:%d\n",m_frameBuffer);
    }
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
    
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              m_renderBuffer);
    
    glViewport(0, 0, width, height);
    
    m_simpleProgram = buildProgram(SimpleVertexShader, SimpleFragmentShader);
    glUseProgram(m_simpleProgram);
    
    playOrtho(width, height);
    
}
void RenderingEngine2::playOrtho(float maxX, float maxY)const
{
    float a = 1.0f / maxX;
    float b = 1.0f / maxY;
    float ortho[16] =
    {
        a,  0,  0,  0,
        0,  b,  0,  0,
        0,  0,  -1, 0,
        0,  0,  0,  1
    };
    GLint projectionUniform = glGetUniformLocation(m_simpleProgram, "Projection");
    glUniformMatrix4fv(projectionUniform,1,0,&ortho[0]);
    
}
void RenderingEngine2::playRotation(float degrees)const
{
    float radians = degrees * 3.14159f / 180.0f;
    float s = std::sin(radians);
    float c = std::cos(radians);
    
    float modelView[16] =
    {
        c,  s,  0,  0,
        -s,  c,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    };
    GLint modelViewUniform = glGetUniformLocation(m_simpleProgram, "ModelView");
    glUniformMatrix4fv(modelViewUniform, 1, 0, &modelView[0]);
}
void RenderingEngine2::render()const
{
//    serverSocket->run();
//    clientSocket->run();
//    printf("run\n");
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    playRotation(0.0f);
    
    GLuint position = glGetAttribLocation(m_simpleProgram, "Position");
    GLuint color = glGetAttribLocation(m_simpleProgram, "SourceColor");
    
    glEnableVertexAttribArray(position);
    glEnableVertexAttribArray(color);
    
    GLsizei stride = sizeof(Vertex);
    const GLvoid * pCoords = &Verteces[0].Position[0];
    const GLvoid * pColors = &Verteces[0].Color[0];
    
    glVertexAttribPointer(position, 2, GL_FLOAT, GL_FALSE, stride, pCoords);
    glVertexAttribPointer(color, 4, GL_FLOAT, GL_FALSE, stride, pColors);
    
    GLsizei vertexCount = sizeof(Verteces)/sizeof(Vertex);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    
    glDisableVertexAttribArray(position);
    glDisableVertexAttribArray(color);
    
}
void RenderingEngine2::updateAnimation(float timeStep)
{
    
}
GLuint RenderingEngine2::buildShader(const char *source, GLenum type) const
{
    GLuint shaderHandler = glCreateShader(type);
    if (shaderHandler == GL_FALSE)
    {
        printf("shaderHandler faild :%d\n",shaderHandler);
        return NULL;
    }else
    {
        printf("shaderHandler success:%d\n",shaderHandler);
    }
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
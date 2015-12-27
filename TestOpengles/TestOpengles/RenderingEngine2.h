//
//  RenderingEngine2.h
//  TestOpengles
//
//  Created by oceantech02 on 15/12/13.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#ifndef RenderingEngine2_h
#define RenderingEngine2_h

#include "IRenderingEngine.h"
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>

class RenderingEngine2 : public IRenderingEngine
{
public:
    RenderingEngine2();
    void    initialize(int width, int height);
    void    render() const;
    void    updateAnimation(float timeStep);
    
private:
    void    playOrtho(float maxX, float maxY) const;
    void    playRotation(float degrees) const;

    GLuint  buildShader(const char * source, GLenum type) const;
    GLuint  buildProgram(const char * vShader, const char * fShader) const;
    GLuint  m_renderBuffer;
    GLuint  m_frameBuffer;
    GLuint  m_simpleProgram;
    GLuint  m_vertexBuffer;
    GLuint  m_indexBuffer;
    //
    //    SocketClient * clientSocket;
    //    SocketServer * serverSocket;
    
};

#endif /* RenderingEngine2_h */

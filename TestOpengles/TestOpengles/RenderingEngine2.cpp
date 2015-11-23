//
//  RenderingEngine2.cpp
//  TestOpengles
//
//  Created by 张洪星 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#include "IRenderingEngine.h"
#include <OpenGLES/ES2/gl.h>

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

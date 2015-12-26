//
//  GLView.m
//  TestOpengles
//
//  Created by oceantech02 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#import "GLView.h"
#include "RenderingEngine2.h"
#include <OpenGLES/ES3/glext.h>


@implementation GLView

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

- (id) initWithFrame:(CGRect)frame
{
    
    if (self = [super initWithFrame:frame])
    {
//        NSLog(@"glview init frame");
        
//        GLuint renderBuffer;
//        glGenFramebuffers(1, &renderBuffer);
//        if (renderBuffer == GL_FALSE)
//        {
//            printf("render buffer faild :%d\n",renderBuffer);
//        }else
//        {
//            printf("render buffer success:%d\n",renderBuffer);
//        }
    
        
        CAEAGLLayer * eaglLayer = (CAEAGLLayer *)super.layer;
        eaglLayer.opaque = true;
        
        EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;
        m_context = [[EAGLContext alloc]initWithAPI:api];
        
        if (!m_context || ![EAGLContext setCurrentContext:m_context])
        {
            return nil;
        }
        
        renderingEngine = CreateRenderer2();

        [m_context renderbufferStorage:GL_RENDERBUFFER
                          fromDrawable:eaglLayer];
        
        renderingEngine->initialize(frame.size.width, frame.size.height);
        
        
        CADisplayLink * displayLink = [CADisplayLink displayLinkWithTarget:self
                                                                  selector:@selector(drawView:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
    }
    return self;
}

- (void) drawView:(CADisplayLink *)displayLink
{
//    NSLog(@"draw view");
//    displayLink.timestamp;
    
    renderingEngine->render();
    [m_context presentRenderbuffer:GL_RENDERBUFFER];
}

@end

//
//  GLView.m
//  TestOpengles
//
//  Created by oceantech02 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#import "GLView.h"


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
        CADisplayLink * displayLink = [CADisplayLink displayLinkWithTarget:self
                                                                  selector:@selector(drawView:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
    }
    return self;
}

- (void) drawView:(CADisplayLink *)displayLink
{
//    NSLog(@"draw view");
    
    
}

@end

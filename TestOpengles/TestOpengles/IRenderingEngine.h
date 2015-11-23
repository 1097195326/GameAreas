//
//  IRenderingEngine.h
//  TestOpengles
//
//  Created by 张洪星 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#ifndef IRenderingEngine_h
#define IRenderingEngine_h

struct IRenderingEngine * CreateRenderer2();

struct IRenderingEngine
{
    virtual void initialize(int width, int height) = 0;
    virtual void render() const = 0;
    virtual void updateAnimation(float timeStep) = 0;
    virtual ~IRenderingEngine() {};
};
#endif /* IRenderingEngine_h */

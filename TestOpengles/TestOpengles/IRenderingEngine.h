//
//  IRenderingEngine.h
//  TestOpengles
//
//  Created by 张洪星 on 15/11/19.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#ifndef IRenderingEngine_h
#define IRenderingEngine_h

#include "Vector.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

struct IRenderingEngine * CreateRenderer2();
struct IResourceManager * CreateResourceManager();

struct IRenderingEngine
{
    virtual void initialize(int width, int height) = 0;
    virtual void render() const = 0;
    virtual void updateAnimation(float timeStep) = 0;
    virtual ~IRenderingEngine() {};
};
struct IResourceManager
{
    virtual string getResourcePath() const = 0;
    virtual void loadPngImage(const string & name) = 0;
    virtual void * getImageData() = 0;
    virtual ivec2 getImageSize() = 0;
    virtual void unloadImage() = 0;
    virtual ~IResourceManager(){}
};

#endif /* IRenderingEngine_h */

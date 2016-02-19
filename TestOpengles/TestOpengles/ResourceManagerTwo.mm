//
//  ResourceManagerTwo.cpp
//  TestOpengles
//
//  Created by oceantech02 on 16/2/19.
//  Copyright © 2016年 张洪星. All rights reserved.
//

#include "ResourceManagerTwo.hpp"


namespace drawl {
    IResourceManager * CreateResourceManager()
    {
        return new ResourceManagerTwo();
    }
    ResourceManagerTwo::ResourceManagerTwo()
    {
        
    }
    ResourceManagerTwo::~ResourceManagerTwo()
    {
        
    }
    string ResourceManagerTwo::getResourcePath() const
    {
        NSString * bundlePath = [[NSBundle mainBundle] resourcePath];
        return [bundlePath UTF8String];
    }
    void ResourceManagerTwo::loadPngImage(const string & name)
    {
        NSString * basePath = [[NSString alloc] initWithUTF8String:name.c_str()];
        NSBundle * mainBundel = [NSBundle mainBundle];
        NSString * fullPath = [mainBundel pathForResource:basePath ofType:@"png"];
        
        UIImage * uiImage = [[UIImage alloc]initWithContentsOfFile:fullPath];
        
        CGImageRef cgImage = uiImage.CGImage;
        m_imageSize.x = (int)CGImageGetWidth(cgImage);
        m_imageSize.y = (int)CGImageGetHeight(cgImage);
        
        m_imageData = CGDataProviderCopyData(CGImageGetDataProvider(cgImage));
    }
    void * ResourceManagerTwo::getImageData()
    {
        return (void *) CFDataGetBytePtr(m_imageData);
    }
    ivec2 ResourceManagerTwo::getImageSize()
    {
        return m_imageSize;
    }
    void ResourceManagerTwo::unloadImage()
    {
        CFRelease(m_imageData);
    }


}
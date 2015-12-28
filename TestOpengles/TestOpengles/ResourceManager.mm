//
//  ResourceManager.cpp
//  TestOpengles
//
//  Created by oceantech02 on 15/12/17.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#include "ResourceManager.hpp"
#include <UIKit/UIKit.h>

string ResourceManager::getResourcePath() const
{
    NSString * bundlePath = [[NSBundle mainBundle] resourcePath];
    return [bundlePath UTF8String];
}
void ResourceManager::loadPngImage(const string & name)
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
void * ResourceManager::getImageData()
{
    return (void *) CFDataGetBytePtr(m_imageData);
}
ivec2 ResourceManager::getImageSize()
{
    return m_imageSize;
}
void ResourceManager::unloadImage()
{
    CFRelease(m_imageData);
}


ResourceManager * createResourceManager()
{
    return new ResourceManager();
}
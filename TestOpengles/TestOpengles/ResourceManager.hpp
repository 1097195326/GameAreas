//
//  ResourceManager.hpp
//  TestOpengles
//
//  Created by oceantech02 on 15/12/17.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include "IRenderingEngine.h"

#include <QuartzCore/QuartzCore.h>

class ResourceManager : public IResourceManager
{
public:
    string getResourcePath() const;
    void loadPngImage(const string & name);
    void * getImageData();
    ivec2 getImageSize();
    void unloadImage();
private:
    CFDataRef   m_imageData;
    ivec2       m_imageSize;
};

#endif /* ResourceManager_hpp */

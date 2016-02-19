//
//  ResourceManagerTwo.hpp
//  TestOpengles
//
//  Created by oceantech02 on 16/2/19.
//  Copyright © 2016年 张洪星. All rights reserved.
//

#ifndef ResourceManagerTwo_hpp
#define ResourceManagerTwo_hpp

#include "IRenderingEngine.h"
#include <QuartzCore/QuartzCore.h>
#include <UIKit/UIKit.h>

namespace drawl {
    
    class ResourceManagerTwo : public IResourceManager
    {
    public:
        string getResourcePath() const;
        void loadPngImage(const string & name);
        void * getImageData();
        ivec2 getImageSize();
        void unloadImage();
        
        ResourceManagerTwo();
        ~ResourceManagerTwo();
    private:
        CFDataRef   m_imageData;
        ivec2       m_imageSize;
    };
    
    
    
}
#endif /* ResourceManagerTwo_hpp */

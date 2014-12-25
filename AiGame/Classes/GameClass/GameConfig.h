//
//  GameConfig.h
//  AiGame
//
//  Created by admin on 12/25/14.
//
//

#ifndef __AiGame__GameConfig__
#define __AiGame__GameConfig__

#include <stdio.h>
#include "cocos2d.h"


cocos2d::Size getVisibleSize()
{
    static bool isFirst = false;
    static cocos2d::Size  visibleSize;
    if (!isFirst) {
        isFirst = true;
        visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    }
    return visibleSize;
}
cocos2d::Vec2 getOrigin()
{
    static bool isFirst = false;
    static cocos2d::Vec2 origin;
    if (!isFirst) {
        isFirst = true;
        origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    }
    return origin;
}


#endif /* defined(__AiGame__GameConfig__) */

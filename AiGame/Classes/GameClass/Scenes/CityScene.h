//
//  CityScene.h
//  AiGame
//
//  Created by admin on 12/25/14.
//
//

#ifndef __AiGame__CityScene__
#define __AiGame__CityScene__

#include <stdio.h>
#include "cocos2d.h"

class CityScene : public cocos2d::Layer{
public:
    static cocos2d::Scene * createScene();
    
    virtual bool init();
    
    CREATE_FUNC(CityScene);
};
#endif /* defined(__AiGame__CityScene__) */

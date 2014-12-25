//
//  CityScene.cpp
//  AiGame
//
//  Created by admin on 12/25/14.
//
//

#include "CityScene.h"
#include "GameConfig.h"
USING_NS_CC;

Scene * CityScene::createScene()
{
    Scene * scene = Scene::create();
    Layer * layer = CityScene::create();
    scene->addChild(layer);
    return scene;
}
bool CityScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize = getVisibleSize();
    Vec2 origin = getOrigin();
    
    Sprite * mubiao = Sprite::create("Assert/Mubiao_Aigame_UI.png");
    mubiao->setPosition(Vec2(origin.x + visibleSize.width * 0.5,
                             origin.y + visibleSize.height * 0.5));
    this->addChild(mubiao,1);

    return true;
}

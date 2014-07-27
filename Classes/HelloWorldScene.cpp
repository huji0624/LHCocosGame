#include "HelloWorldScene.h"
#include "PlayScene.h"
#include "UMShareButton.h"
#include "ThirdPartyHelper.h"
#include "UIButton.h"
#include "DeveloperInfoScence.h"

USING_NS_CC;
USING_NS_UM_SOCIAL;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->addChild(DeveloperInfo::DevInfoButton("devinfo.png"));
    
    
    return true;
}

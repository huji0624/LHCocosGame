#include "HelloWorldScene.h"
#include "PlayScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* GameOverScene::createScene(int level)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();
    layer->initWithLevel(level);
    
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    auto easyLabel = LabelTTF::create("Again", "Arial", 34);
    auto easyItem = MenuItemLabel::create(easyLabel, CC_CALLBACK_1(GameOverScene::again, this));
    easyItem->setPosition(visibleSize.width/2-easyItem->getContentSize().width/2, visibleSize.height/10*6);
    
    auto hardLabel = LabelTTF::create("Back", "Arial", 34);
    auto hardItem = MenuItemLabel::create(hardLabel, CC_CALLBACK_1(GameOverScene::back, this));
    hardItem->setPosition(visibleSize.width/2-hardItem->getContentSize().width/2, visibleSize.height/10*4);

    // create menu, it's an autorelease object
    auto menu = Menu::create(easyItem,hardItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Game Over", "Arial", 54);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(visibleSize.width/2-label->getContentSize().width/2,
                            origin.y + visibleSize.height/5*4 - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label);
    
    return true;
}

static void toPlay(int level){
    auto tran =  TransitionMoveInR::create(0.3, PlayScene::createScene(level));
    Director::getInstance()->replaceScene(tran);
}

void GameOverScene::again(cocos2d::Ref *pSender){
    toPlay(rlevel);
}

void GameOverScene::back(cocos2d::Ref *pSender){
    auto tran =  TransitionMoveInR::create(0.3, HelloWorld::createScene());
    Director::getInstance()->replaceScene(tran);
}

void GameOverScene::initWithLevel(int level){
    rlevel = level;
}


//------.cpp
#include "GameOverScene.h"
Scene* GameOverScene::createScene(cocos2d::CCDictionary *dic)
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	layer->initDict(dic);
	scene->addChild(layer);
	return scene;
}

GameOverScene::~GameOverScene(){
}
bool GameOverScene::initDict(cocos2d::CCDictionary *dic)
{
    
	return true;
}
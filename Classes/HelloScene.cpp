#include "HelloScene.h"
#include "MenuScene.h"

USING_NS_CC;


Scene* HelloScene::createScene()
{
    auto scene = Scene::create();
	auto layer = HelloScene::create();
    scene->addChild(layer);
    return scene;
}


bool HelloScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/bgMusic1.wav");
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/bgMusic1.wav");

	this->addUI();

	this->schedule(schedule_selector(HelloScene::turnToMenuScene), 1.0f);

    return true;
}


void HelloScene::addUI()
{
	auto WIN_SIZE = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::create("Logo.png");
	bg->setPosition(WIN_SIZE / 2);
	this->addChild(bg);
}


void HelloScene::turnToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	auto tt = CCTransitionRotoZoom::create(1.0, scene);
	Director::getInstance()->replaceScene(tt);
}

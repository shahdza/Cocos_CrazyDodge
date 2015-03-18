#include "MenuScene.h"
#include "GameScene.h"
#include "OptionsScene.h"
#include "AboutScene.h"

USING_NS_CC;


Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
	auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}


bool MenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	this->addUI();
    
    return true;
}


void MenuScene::addUI()
{
	auto bg = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("MenuUI/MenuUI.ExportJson");
	this->addChild(bg);

	// play button
	auto btnPlay = (Button*)Helper::seekWidgetByName(bg, "BtnPlay");
	btnPlay->addTouchEventListener(CC_CALLBACK_2(MenuScene::turnToGameScene, this));

	// options button
	auto btnOptions = (Button*)Helper::seekWidgetByName(bg, "BtnOptions");
	btnOptions->addTouchEventListener(CC_CALLBACK_2(MenuScene::turnToOptionsScene, this));

	// about button
	auto btnAbout = (Button*)Helper::seekWidgetByName(bg, "BtnAbout");
	btnAbout->addTouchEventListener(CC_CALLBACK_2(MenuScene::turnToAboutScene, this));

	// quit button
	auto btnQuit = (Button*)Helper::seekWidgetByName(bg, "BtnQuit");
	btnQuit->addTouchEventListener(CC_CALLBACK_2(MenuScene::quit, this));

	// record
	auto textScore = (TextBMFont*)Helper::seekWidgetByName(bg, "Score");
	double score = UserDefault::getInstance()->getDoubleForKey("Record", 0.000);
	char s[50];
	sprintf(s, "%.3f", score);
	textScore->setString(s);
}


void MenuScene::turnToGameScene(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto scene = GameScene::createScene();
		auto tt = TransitionFade::create(1.0, scene);
		Director::getInstance()->replaceScene(tt);
	}
}


void MenuScene::turnToOptionsScene(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto scene = OptionsScene::createScene();
		auto tt = TransitionPageTurn::create(0.5, scene, false);
		Director::getInstance()->replaceScene(tt);
	}
}


void MenuScene::turnToAboutScene(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto scene = AboutScene::createScene();
		auto tt = TransitionPageTurn::create(0.5, scene, false);
		Director::getInstance()->replaceScene(tt);
	}
}


void MenuScene::quit(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		Director::getInstance()->end();
		exit(0);
	}
}


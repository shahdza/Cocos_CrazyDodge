#include "OptionsScene.h"
#include "MenuScene.h"

USING_NS_CC;

#define MUSIC "Music/bgMusic.wav"


Scene* OptionsScene::createScene()
{
    auto scene = Scene::create();
	auto layer = OptionsScene::create();
    scene->addChild(layer);
    return scene;
}


bool OptionsScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	this->addUI();

    return true;
}


void OptionsScene::addUI()
{
	auto bg = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("OptionsUI/OptionsUI.ExportJson");
	this->addChild(bg);

	// back button
	auto btnBack = (Button*)Helper::seekWidgetByName(bg, "BtnBack");
	btnBack->addTouchEventListener(CC_CALLBACK_2(OptionsScene::turnToMenuScene, this));

	// checkbox
	auto checkBox = (CheckBox*)Helper::seekWidgetByName(bg, "CheckBox");
	checkBox->addTouchEventListener(CC_CALLBACK_2(OptionsScene::setSound, this));
	bool state = UserDefault::getInstance()->getBoolForKey("Music", true);
	checkBox->setSelectedState(state);
}


void OptionsScene::setSound(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto checkBox = (CheckBox*)sender;
		if (checkBox->getSelectedState() == true)
		{
			UserDefault::getInstance()->setBoolForKey("Music", false);
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		}
		else
		{
			UserDefault::getInstance()->setBoolForKey("Music", true);
		}
	}
}


// 返回菜单界面
void OptionsScene::turnToMenuScene(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto scene = MenuScene::createScene();
		auto tt = TransitionPageTurn::create(0.5, scene, true);
		Director::getInstance()->replaceScene(tt);
	}
}
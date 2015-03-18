#include "AboutScene.h"
#include "MenuScene.h"

USING_NS_CC;


Scene* AboutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
    return scene;
}


bool AboutScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	this->addUI();
    
    return true;
}


void AboutScene::addUI()
{
	auto bg = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("AboutUI/AboutUI.ExportJson");
	this->addChild(bg);

	// back button
	auto btnBack = (Button*)Helper::seekWidgetByName(bg, "BtnBack");
	btnBack->addTouchEventListener(CC_CALLBACK_2(AboutScene::turnToMenuScene, this));

}


// 返回菜单界面
void AboutScene::turnToMenuScene(Ref* sender, ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto scene = MenuScene::createScene();
		auto tt = TransitionPageTurn::create(0.5, scene, true);
		Director::getInstance()->replaceScene(tt);
	}
}


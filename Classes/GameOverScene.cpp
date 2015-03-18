#include "GameOverScene.h"
#include "GameScene.h"
#include "MenuScene.h"

USING_NS_CC;


Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();
	auto layer = GameOverScene::create();
    scene->addChild(layer);
    return scene;
}


bool GameOverScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	this->getData();
	this->addUI();

	this->scheduleUpdate();

    return true;
}


// 获取分数数据
void GameOverScene::getData()
{
	this->record = UserDefault::getInstance()->getDoubleForKey("Record", 0.000);
	this->score = UserDefault::getInstance()->getDoubleForKey("Score", 0.000);
	this->addScore = 0.0;

	if (this->score > this->record)
	{
		UserDefault::getInstance()->setDoubleForKey("Record", this->score);
		UserDefault::getInstance()->flush();
	}
}


// 加载UI
void GameOverScene::addUI()
{
	this->bg = (Layout*)cocostudio::GUIReader::getInstance()->widgetFromJsonFile("GameOverUI/GameOverUI.ExportJson");
	this->addChild(this->bg);

	// again button
	auto btnAgain = (Button*)Helper::seekWidgetByName(bg, "BtnAgain");
	btnAgain->addTouchEventListener(CC_CALLBACK_2(GameOverScene::turnToGameScene, this));

	// back button
	auto btnBack = (Button*)Helper::seekWidgetByName(bg, "BtnBack");
	btnBack->addTouchEventListener(CC_CALLBACK_2(GameOverScene::turnToMenuScene, this));

	// 新分数
	this->text =(TextBMFont*) ui::Helper::seekWidgetByName(this->bg, "NewScore");
	char str[50];
	sprintf(str, "%.3f", this->score);
	this->text->setString(str);

	// 历史记录
	auto rd = (TextBMFont*)ui::Helper::seekWidgetByName(this->bg, "Score");
	char s[50];
	sprintf(s, "%.3f", this->record);
	rd->setString(s);

	// New Logo --> New_IMG
	this->image = (ImageView*)ui::Helper::seekWidgetByName(this->bg, "New_IMG");
	this->image->setVisible(false);
	this->image->setScale(0.0);
}


// 分数动态效果
void GameOverScene::update(float dt)
{
	char s[50];
	double delta = this->score * dt;
	if (this->addScore + delta >= this->score)
	{
		sprintf(s, "%.3f", this->score);
		this->text->setString(s);

		this->unscheduleUpdate();
		this->showNewLogo();
	}
	else 
	{
		this->addScore += delta;
		sprintf(s, "%.3f", this->addScore);
		this->text->setString(s);
	}
}


// 显示是否为新记录
void GameOverScene::showNewLogo()
{
	if (this->score > this->record)
	{
		this->image->setVisible(true);
		auto *scaleBig = ScaleTo::create(0.4f, 0.7f);
		auto *delay = DelayTime::create(0.1f);
		auto *scaleSmall = ScaleTo::create(0.2f, 0.5f);
		auto *seq = Sequence::create(scaleBig, delay, scaleSmall, NULL);
		this->image->runAction(seq);
	}
}


// 再玩一次
void GameOverScene::turnToGameScene(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto scene = GameScene::createScene();
		auto tt = TransitionFlipX::create(0.5f, scene, TransitionScene::Orientation::LEFT_OVER);
		Director::getInstance()->replaceScene(tt);
	}
}


// 返回菜单界面
void GameOverScene::turnToMenuScene(Ref* sender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		auto scene = MenuScene::createScene();
		auto tt = TransitionFade::create(1.0, scene);
		Director::getInstance()->replaceScene(tt);
	}
}


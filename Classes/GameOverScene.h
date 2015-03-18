#ifndef __GameOverScene_H__
#define __GameOverScene_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace cocostudio;
class GameOverScene : public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();
	CREATE_FUNC(GameOverScene);

	void getData();
	void addUI();
	void update(float dt);
	void showNewLogo();

	void turnToGameScene(Ref* sender, Widget::TouchEventType type);
	void turnToMenuScene(Ref* sender, Widget::TouchEventType type);

private:
	Layout* bg;
	TextBMFont* text;
	ImageView* image;
	double t;

	double record;
	double score;
	double addScore;
};

#endif // __GameOverScene_H__

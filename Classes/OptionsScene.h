#ifndef __OptionsScene_H__
#define __OptionsScene_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace cocostudio;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class OptionsScene : public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();  
	CREATE_FUNC(OptionsScene);

	void addUI();

	void setSound(Ref* sender, Widget::TouchEventType type);
	void turnToMenuScene(Ref* sender, Widget::TouchEventType type);
};

#endif // __OptionsScene_H__

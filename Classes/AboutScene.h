#ifndef __AboutScene_H__
#define __AboutScene_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace cocostudio;

class AboutScene : public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();  
	CREATE_FUNC(AboutScene);

	void addUI();
	void turnToMenuScene(Ref* sender, ui::Widget::TouchEventType type);
};

#endif // __AboutScene_H__

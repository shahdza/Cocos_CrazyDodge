#ifndef __HelloScene_H__
#define __HelloScene_H__

#include "cocos2d.h"
USING_NS_CC;

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class HelloScene : public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();  
	CREATE_FUNC(HelloScene);

	void addUI();
	void turnToMenuScene(float dt);
};

#endif // __HelloScene_H__

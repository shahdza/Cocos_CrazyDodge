#include "AppDelegate.h"
#include "HelloScene.h"
#include "AboutScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{

}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("CrazyDodge");
        director->setOpenGLView(glview);
    }

	glview->setDesignResolutionSize(800, 480, ResolutionPolicy::EXACT_FIT);

	director->setAnimationInterval(1.0 / 60);
    director->setDisplayStats(false);

	this->addResource();

    auto scene = HelloScene::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::addResource()
{
	FileUtils::getInstance()->addSearchPath("Music");
	FileUtils::getInstance()->addSearchPath("UI");
}
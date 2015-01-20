#include "AppDelegate.h"


USING_NS_CC;

#define TARGETHEIGHT 720
#define TARGETWIDTH 1280

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
        glview = GLView::create("RescuePrincess");
		glview->setFrameSize(640, 360);
        director->setOpenGLView(glview);
    }
	glview->setViewPortInPoints(0, 0, 640, 360);
	glview->setDesignResolutionSize(TARGETWIDTH, TARGETHEIGHT, ResolutionPolicy::EXACT_FIT);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);




	//添加搜索路径,Resources文件夹下自己添加
	FileUtils::getInstance()->addSearchPath("fonts/");


    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();

    // run
    director->runWithScene();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

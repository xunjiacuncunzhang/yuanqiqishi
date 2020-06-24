#include "gamePause.h"
#include "cocostudio/CocoStudio.h"
#include"SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include"SetScene.h"
#include"MyScene.h"

USING_NS_CC;


Scene* gamePause::scene(cocos2d::RenderTexture* sqr)
{
	Scene* scene = Scene::create();
	gamePause* layer = gamePause::create();
	scene->addChild(layer, 1);
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	Sprite* back_sqr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_sqr->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	back_sqr->setFlipY(true);
	back_sqr->setColor(cocos2d::Color3B(211, 211, 211));
	scene->addChild(back_sqr);
	return scene;
}

//参考：https://blog.csdn.net/Evankaka/article/details/42936117


bool gamePause::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic("backgroundmusic.mp3", true);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//继续游戏
	MenuItemImage *pContinueItem = MenuItemImage::create(
		"start.png",
		"start.png",
		this,
		menu_selector(gamePause::menuContinueCallback));

	pContinueItem->setPosition(Point(visibleSize.width / 2+100, visibleSize.height / 2 - 100));
	pContinueItem->setScale(0.7f);

	/*回主界面*/
	MenuItemImage *pLoginItem = MenuItemImage::create(
		"close.png",
		"close.png",
		this,
		menu_selector(gamePause::menuLogin));

	pLoginItem->setPosition(Point(visibleSize.width / 2-100, visibleSize.height / 2 -100));


	Menu* pMenu = Menu::create(pContinueItem, NULL);
	pMenu->setPosition(Point::ZERO);

	Menu* pMenu1 = Menu::create(pLoginItem, NULL);
	pMenu1->setPosition(Point::ZERO);
	this->addChild(pMenu, 2);
	this->addChild(pMenu1, 2);

	return true;
}


void gamePause::menuContinueCallback(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	Director::getInstance()->popScene();

}

//回主界面
void  gamePause::menuLogin(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	Director::getInstance()->replaceScene(MyWorld::createScene());
}


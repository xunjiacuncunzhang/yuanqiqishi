#include "gamePause.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include"SetScene.h"

USING_NS_CC;


Scene* gamePause::scene(cocos2d::RenderTexture* sqr)
{
	Scene *pauseScene = Scene::create();
	gamePause *pauseLayer = gamePause::create();
	pauseScene->addChild(pauseLayer, 1);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *background = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2)); 

	background->setScale(0.1);
	background->setFlippedY(true);            
	background->setColor(cocos2d::Color3B::GRAY); 
	pauseScene->addChild(background);


	Sprite *smallBackground = Sprite::create("pause.png");
	smallBackground->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	pauseScene->addChild(smallBackground);

	return pauseScene;
}

//参考：https://blog.csdn.net/Evankaka/article/details/42936117


bool gamePause::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//继续游戏
	MenuItemImage *pContinueItem = MenuItemImage::create(
		"start.png",
		"start.png",
		this,
		menu_selector(gamePause::menuContinueCallback));

	pContinueItem->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 - 60));


	//回主界面
	/*MenuItemImage *pLoginItem = MenuItemImage::create(
		"close.png",
		"close.png",
		this,
		menu_selector(gamePause::menuLogin));

	pContinueItem->setPosition(Point(visibleSize.width / 2-20, visibleSize.height / 2 + 30));*/


	Menu* pMenu = Menu::create(pContinueItem, NULL);
	pMenu->setPosition(Point::ZERO);
	this->addChild(pMenu, 2);

	return true;
}


void gamePause::menuContinueCallback(Ref* pSender)
{
	Director::getInstance()->popScene();

}

////回主界面
//void  gamePause::menuLogin(Ref* pSender)
//{
//	Director::getInstance()->replaceScene(MenuScene::createScene());
//}


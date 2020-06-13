#include"GamePause.h"
#include"cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
Scene* GamePause::scene(RenderTexture* sqr)
{
	Scene* scene = Scene::create();
	GamePause* layer = GamePause::create();
	scene->addChild(layer, 1);
	//从游戏界面获取sqr图片创建精灵
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	Sprite* back_sqr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_sqr->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	back_sqr->setFlipY(true);
	back_sqr->setColor(cocos2d::Color3B(211, 211, 211));
	scene->addChild(back_sqr);
	return scene;
}
bool GamePause::init()
{
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	Point origin = Director::sharedDirector()->getVisibleOrigin();
	MenuItemImage* pContinueItem = MenuItemImage::create(
		"continue.png",
		"continue.png",
		this,
		menu_selector(GamePause::continueCallBack));
	pContinueItem->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 30);
	Menu* pMenu = Menu::create(pContinueItem, NULL);
	pMenu->setPosition(Vec2(0,0));
	this->addChild(pMenu, 2);

	return true;
}
void GamePause::continueCallBack(Object* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	Director::sharedDirector()->popScene();
}
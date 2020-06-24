#include"MyScene.h"
#include "SimpleAudioEngine.h"
#include"HelloWorldScene.h"
#include"SetScene.h"
#include"safemap.h"
#include"loading.h"
#include"gamePause.h"
USING_NS_CC;
Scene* MyWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = MyWorld::create();
	scene->addChild(layer);
	return scene;
}

bool MyWorld::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (!Layer::init())
	{
		return false;
	}
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("backgroundmusic.mp3",true);
	auto* background = Sprite::create("background.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(0.9);
	this->addChild(background);
	
	Size size = Director::getInstance()->getVisibleSize();
	
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MyWorld::menuCloseCallback, this));
	float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
	float y = origin.y + closeItem->getContentSize().height / 2;
	closeItem->setPosition(Vec2(x, y));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	//ÉèÖÃ¹Ø±Õ°´Å¥
	auto* pButton1 = MenuItemImage::create("button.jpg", "buttonselected.jpg", this, menu_selector(MyWorld::start));
	auto* label1 = LabelTTF::create("New Game", "Arial", 40);
	auto* pLabel1 = MenuItemLabel::create(label1, this, menu_selector(MyWorld::start));
	auto* button1 = Menu::create(pButton1, pLabel1, NULL);
	button1->setAnchorPoint(Vec2(0, 0));
	button1->setPosition(size.width * 1 / 5, size.height / 2);
	button1->setScale(0.7f);
	addChild(button1);
	auto* pButton2 = MenuItemImage::create("button.jpg", "buttonselected.jpg", this, menu_selector(MyWorld::set));
	auto* label2 = LabelTTF::create("Set Sound", "Arial", 40);
	auto* pLabel2 = MenuItemLabel::create(label2, this, menu_selector(MyWorld::set));
	auto* button2 = Menu::create(pButton2, pLabel2, NULL);
	button2->setAnchorPoint(Vec2(0, 0));
	button2->setPosition(size.width * 1 / 5, size.height / 2 - 90);
	button2->setScale(0.7f);
	addChild(button2);
	auto* pButton3 = MenuItemImage::create("button.jpg", "buttonselected.jpg", this, menu_selector(MyWorld::pause));
	auto* label3 = LabelTTF::create("Pause", "Arial", 40);
	auto* pLabel3 = MenuItemLabel::create(label3, this, menu_selector(MyWorld::pause));
	auto* button3 = Menu::create(pButton3, pLabel3, NULL);
	button3->setAnchorPoint(Vec2(0, 0));
	button3->setPosition(size.width * 1 / 5, size.height / 2 - 180);
	button3->setScale(0.7f);
	addChild(button3);



	return true;
}
void MyWorld::pause(cocos2d::Ref*pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	RenderTexture* rendertexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	rendertexture->begin();
	this->getParent()->visit();
	rendertexture->end();
	Director::sharedDirector()->pushScene(gamePause::scene(rendertexture));
}
void MyWorld::set(cocos2d::Ref* pSender)
{
	Director::sharedDirector()->pushScene(TransitionCrossFade::create(0.5f, SetWorld::createScene()));
}
void MyWorld::start(cocos2d::Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionCrossFade::create(0.5f, Loading::createScene()));
}
void MyWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
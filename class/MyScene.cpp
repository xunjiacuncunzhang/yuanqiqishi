#include"MyScene.h"
#include "SimpleAudioEngine.h"
#include"HelloWorldScene.h"
#include"SetScene.h"
#include"safemap.h"
#include"loading.h"
#include"GamePause.h"
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
	//auto *layer1 = Layer::create();
	//auto *pBackground = Sprite::create("background.png");
	//pBackground->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height / 2 + origin.y));
	//layer1->addChild(pBackground);
	//创建背景层
	//auto* layer2 = Layer::create();
	//auto* pPlane = Sprite::create("plane.jpg");
	//pPlane->setScale(0.5f);
	//pPlane->setPosition(Vec2(visibleSize.width / 2 + origin.x,visibleSize.height*1/8+  origin.y));
	//layer2->addChild(pPlane);
	//创建飞机层
	//auto* layer3 = Layer::create();
	//auto* number = LabelTTF::create("13400", "Arial", 32);
	//number->setPosition(Vec2(visibleSize.width*5/6 + origin.x, visibleSize.height*5/6 + origin.y));//计分层
	//layer3->addChild(number);
	//this->addChild(layer1);
	//this->addChild(layer2);
	//this->addChild(layer3);
	//auto label1 = Label::create("This is the first label!", "Arial", 36, Size::ZERO, TextHAlignment::LEFT,TextVAlignment::TOP);
	//label1->setPosition(210, 310);
	//addChild(label1);
	Size size = Director::getInstance()->getVisibleSize();
	//auto* background = Sprite::create("background.png");
	//background->setPosition(size.width / 2, size.height / 2);
	//background->setScale(1.1f);
	//addChild(background, 0);
	//auto* button1 = Sprite::create("button.jpg");
	//button1->setPosition(size.width*3/4, size.height / 2);
	//button1->setScale(0.2f);
	//addChild(button1, 1);
	//auto* button2 = Sprite::create("button.jpg");
	//button2->setPosition(size.width * 3 / 4, size.height / 2 - 90);
	//button2->setScale(0.2f);
	//addChild(button2, 1);
	//auto* button3 = Sprite::create("button.jpg");
	//button3->setPosition(size.width * 3 / 4, size.height / 2 - 180);
	//button3->setScale(0.2f);
	//addChild(button3, 1);
	//auto* hero = Sprite::create("hero.jpg");
	//hero->setPosition(0, 0);
	//hero->setAnchorPoint(Vec2(0, 0));
	//hero->setScale(0.9f);
	//addChild(hero, 2);
	//auto label = Label::createWithTTF("Welcome!", "fonts/Marker Felt.ttf", 24);
	
		// position the label on the center of the screen
	//label->setPosition(Vec2(origin.x + visibleSize.width / 2,
	//origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
	//this->addChild(label, 1);
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
	//设置关闭按钮
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
	auto* button2 = Menu::create(pButton2,pLabel2, NULL);
	button2->setAnchorPoint(Vec2(0, 0));
	button2->setPosition(size.width * 1 / 5, size.height/2 - 90);
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
	Director::sharedDirector()->pushScene(GamePause::scene(rendertexture));
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
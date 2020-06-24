#include "safemap.h"
#include"Joystick.h"
#include"MyScene.h"
#include"SetScene.h"
#include"gamePause.h"
#include"SimpleAudioEngine.h"
#include"PlayScene.h"
#include"Player.h"
USING_NS_CC;
backpack safemap::myBag;

Scene* safemap::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = safemap::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool safemap::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	knight = Player::createWithFileName("knight.png");
	knight->InitPlayerSprite("bloodOutside.jpg", "blood.jpg");
	knight->setCurrentBlood(100);
	addChild(knight);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto* map = TMXTiledMap::create("realmap.tmx");
	addChild(map);

	auto* pButton1 = MenuItemImage::create("backbutton.png", "backbuttonselected.png", this, menu_selector(safemap::back));
	auto* button1 = Menu::create(pButton1, NULL, NULL);

	button1->setAnchorPoint(Vec2(0, 0));
	button1->setPosition(visibleSize.width * 8 / 9, visibleSize.height * 8 / 9);
	button1->setScale(0.7f);
	addChild(button1, 1);

	auto* pButton2 = MenuItemImage::create("set.png", "setselected.png", this, menu_selector(safemap::set));
	auto* button2 = Menu::create(pButton2, NULL, NULL);
	button2->setScale(0.7f);
	button2->setAnchorPoint(Vec2(0, 0));
	button2->setPosition(visibleSize.width * 8 / 9, visibleSize.height * 3 / 4);
	addChild(button2, 1);

	auto* pButton3 = MenuItemImage::create("continue.png", "continue.png", this, menu_selector(safemap::pause));
	auto* button3 = Menu::create(pButton3, NULL, NULL);
	button3->setAnchorPoint(Vec2(0, 0));
	button3->setPosition(visibleSize.width * 8 / 9, visibleSize.height * 22 / 36);
	//button3->setScale(0.7f);
	button3->setScaleX(0.45);
	button3->setScaleY(0.7);
	addChild(button3, 1);

	auto* pButton4 = MenuItemImage::create("bookbutton.png", "bookbutton.png", this, menu_selector(safemap::book));
	auto* button4 = Menu::create(pButton4, NULL, NULL);

	button4->setAnchorPoint(Vec2(0, 0));
	button4->setPosition(visibleSize.width * 8 / 9, visibleSize.height * 17 / 36);
	button4->setScale(0.7f);
	addChild(button4, 1);

	Sprite* spRocker2 = Sprite::create("joystick.png");//摇杆
	spRocker2->setScale(0.5);
	Sprite* spRockerBG2 = Sprite::create("joystickBG.png");//摇杆背景
	spRockerBG2->setScale(0.7);
	HRocker* rocker2 = HRocker::HRockerWithCenter(Vec2(128.0f, 128.0f), 50.0f, spRocker2, spRockerBG2, false);//创建摇杆
	this->addChild(rocker2, 0, "joystick");//摇杆添加到layer中 
	this->scheduleUpdate();
	Rect rect = Rect(0.5f, 0.0f, 60.0f, 65.0f);
	auto role = Sprite::create("knight.png", rect);
	// role->setScale(0.8);// 被控制的精灵
	role->setPosition(Vec2(300.0f, 200.0f));
	this->addChild(role, 0, "role");
	//Rect rect = Rect(0.0f, 0.0f, 130.0, 130.0);
   // auto role = Sprite::create("test_sprite.png", rect);
   // role->setPosition(Vec2(300.0, 200.0));
   // this->addChild(role, 0, "role");
	auto send = Sprite::create("send.png");
	send->setScale(0.6);
	send->setPosition(432, 552);
	this->addChild(send, 0, "send");


	auto* pbag = MenuItemImage::create("backpack.jpg", "backpack.jpg", this, menu_selector(safemap::bag));
	auto* bag = Menu::create(pbag, NULL, NULL);
	bag->setScale(0.2);
	bag->setAnchorPoint(Vec2::ZERO);
	bag->setPosition(visibleSize.width / 9, visibleSize.height * 7 / 8);
	addChild(bag, 1, "bag");

	return true;
}

void safemap::setHero(Player*player)
{
	this->knight = player;
}


/*让我们的精灵按照摇杆的力度移动距离*/
void safemap::update(float dt)
{
	HRocker* rocker2 = (HRocker*)getChildByName("joystick");
	Vec2 direct = rocker2->getDirection(); // 获取摇杆方向向量
	auto role = getChildByName("role");
	float speed = 3.0f; // 每一帧角色移动的速度
	Size WindowSize = Director::getInstance()->getWinSize(); // 获取窗口大小,防止精灵移动出去
	Vect newPosition = role->getPosition() + direct * speed;
	if (newPosition.x > 0 && newPosition.x < WindowSize.width && newPosition.y > 0 && newPosition.y < WindowSize.height)
	{
		role->setPosition(newPosition);
	}
	auto send = getChildByName("send");
	Vect positionofsend = send->getPosition();
	float distance = sqrt((newPosition.x - positionofsend.x) * (newPosition.x - positionofsend.x) + (newPosition.y - positionofsend.y) * (newPosition.y - positionofsend.y));
	if (distance <= 32)
	{
		Director::sharedDirector()->getInstance()->pushScene(PlayScene::create());
	}
}

void safemap::bag(Ref* pSender)
{
    myBag.add(2,2,knight);
	Director::sharedDirector()->pushScene(myBag.createScene());
}

void safemap::book(Ref* pSender)
{
	Director::sharedDirector()->pushScene(TransitionCrossFade::create(0.5f, enemy::createScene()));
}

void safemap::back(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionCrossFade::create(1.0f, MyWorld::createScene()));
}

void safemap::set(Ref* pSender)
{
	Director::sharedDirector()->pushScene(TransitionCrossFade::create(0.5f, SetWorld::createScene()));
}
void safemap::pause(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	RenderTexture* rendertexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	rendertexture->begin();
	this->getParent()->visit();
	rendertexture->end();
	Director::sharedDirector()->pushScene(gamePause::scene(rendertexture));
}
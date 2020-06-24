#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"PlayScene.h"
#include"gamePause.h"
#include"Player.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	///* 'layer' is an autorelease object*/
	/*auto layer = HelloWorld::create();*/

	// /*add layer as a child to scene*/
	/*scene->addChild(layer);*/

	/*auto layer = gameMap::create();
	scene->addChild(layer);*/

	/*auto layer = playLayer::create();
	scene->addChild(layer);
*/
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	/**  you can create scene with following comment code instead of using csb file.
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
										   "CloseNormal.png",
										   "CloseSelected.png",
										   CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
								origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
							origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	**/

	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	/*auto recMap = TMXTiledMap::create("map1.tmx");
	this->addChild(recMap);*/

	//auto rootNode = CSLoader::createNode("MainScene.csb");//根节点

	//addChild(rootNode);//若将以上两行注释，则表示不使用系统资源

	// Size vsize = Director::getInstance()->getVisibleSize(); 获取可见大小
	// Vec2 = Director::getInstance()->getVisibleOrigin(); 获取OpenGL起点

	//auto label = LabelTTF::create("hello cocos", "Arial", 36); 创建文本框（ARial：字体， 36：大小）
	//label->setPosition(Vec2(origin.x+vsize.width/2, origin.y+vize.height/2));
	//设置位置

	//this->addChild(label); 添加节点

	/*Size vsize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	{
		auto batchnode = SpriteBatchNode::create("diban3.png", 225);
		batchnode->setAnchorPoint(Point(0, 0));
		batchnode->setPosition(origin);
		this->addChild(batchnode);

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				auto sp = Sprite::createWithTexture(batchnode->getTexture());
				sp->setAnchorPoint(Point(0, 0));
				sp->setPosition(Point( 20 * i, 20 * j));
				batchnode->addChild(sp);
			}
		}
	}
*/
	return true;
}

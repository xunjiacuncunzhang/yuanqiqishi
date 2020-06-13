#include "cocos2d.h"
#include"PlayLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"gamePause.h"
#include"SetScene.h"

USING_NS_CC;

bool playLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initMap();
	initHero();
	initNextLevelRoom();
	this->scheduleUpdate();

	//加入宝箱
    auto boxItem1 = MenuItemImage::create(
		"baoxiang.png",
		"baoxiang.png",
		this,
		menu_selector(playLayer::getProps));

	pboxMenu1 = CCMenu::create(boxItem1, NULL);

	TMXObjectGroup *objects = map->objectGroupNamed("box");
	auto boxShowUpPoint = objects->getObject("baoxiang1");

	int x = boxShowUpPoint["x"].asInt();
	int y = boxShowUpPoint["y"].asInt();
	pboxMenu1->setPosition(Vec2(x, y));
	pboxMenu1->setScale(0.6f);
	this->addChild(pboxMenu1, 1);


	//设想这个宝箱出武器，但还没有武器类
	/*auto boxItem2 = MenuItemImage::create(
		"baoxiang.png",
		"baoxiang.png",
		this,
		menu_selector(playLayer::getProps));

    pboxMenu2 = CCMenu::create(boxItem2, NULL);
    TMXObjectGroup *objects2 = map->objectGroupNamed("box");
	auto boxShowUpPoint2 = objects2->getObject("baoxiang2");

	int i = boxShowUpPoint2["x"].asInt();
	int j = boxShowUpPoint2["y"].asInt();
	pboxMenu2->setPosition(Vec2(i, j));
	this->addChild(pboxMenu2, 1);*/


	//游戏暂停菜单
	auto pCloseItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(playLayer::menuPauseCallback));
	
	pMenu1 = CCMenu::create(pCloseItem, NULL);
	pMenu1->setPosition(knight->getPosition().x+300,knight->getPosition().y+100);
	this->addChild(pMenu1, 1);

	//设置
	auto pSetItem = MenuItemImage::create(
		"set.png",
		"set.png",
		this,
		menu_selector(playLayer::menuSetCallback));


	pMenu2 = Menu::create(pSetItem, NULL);
	pMenu2->setAnchorPoint(Vec2(0, 0));
	pMenu2->setPosition(knight->getPosition().x + 300, knight->getPosition().y + 40);
	pMenu2->setScale(0.7f);
	this->addChild(pMenu2,1);


	return true;
}


void playLayer::initMap()
{
	auto *recMap1 = TMXTiledMap::create("map1.tmx");
	auto *recMap2 = TMXTiledMap::create("QishiMap.tmx");

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	switch (rand() % 3)
	{
	case 0:
		map = recMap1;
		recMap1->setAnchorPoint(Vec2(0, 0));
		recMap1->setPosition(origin);
		this->addChild(recMap1, -1);

		break;

	default:
		map = recMap2;
		recMap2->setAnchorPoint(Vec2(0, 0));
		recMap2->setPosition(origin);
		this->addChild(recMap2, -1);

		break;
	}


	//获得碰撞检测层
	block = map->layerNamed("barrier");
	block->setVisible(false);
}

void playLayer::initHero()
{

	//获取人物出生位置
	TMXObjectGroup *objects = map->objectGroupNamed("knight");
	auto playerShowUpPoint = objects->getObject("playerBorn");

	int x = playerShowUpPoint["x"].asInt();
	int y = playerShowUpPoint["y"].asInt();


	//创建一个人物
	knight = Player::createWithFileName("knight.png");

	//加上人物血条
	knight->InitPlayerSprite("bloodOutside.jpg", "blood.jpg");
	knight->setCurrentBlood(80);

	knight->setPosition(Point(x, y));
	knight->setScale(0.6f);
	this->addChild(knight, 0);
	knight->setWalkSpeed(80.0);
}

void playLayer::initNextLevelRoom()
{
	TMXObjectGroup *objects = map->objectGroupNamed("end");
	auto endPoint = objects->getObject("GameEnd");

	int x = endPoint["x"].asInt();
	int y = endPoint["y"].asInt();

	auto nextLevelItem = MenuItemImage::create(
		"gate.png",
		"gate.png",
		this,
		menu_selector(playLayer::nextLevel));

	auto pMenu = CCMenu::create(nextLevelItem, NULL);
	pMenu->setScale(0.8f);
	pMenu->setPosition(Vec2(x,y));
	this->addChild(pMenu, 1);
}


void playLayer::nextLevel(Ref* pSender)
{
	playLayer::knight->retain();
	//从该场景移除
	playLayer::knight->removeFromParent();  
	/*PlayScene::level++;  */       //关卡编号+1

	assert(playLayer::knight->getParent() == nullptr);

	this->cleanup();
	//释放
	this->removeAllChildren(); 
	//进入下一个场景
	Director::getInstance()->pushScene( 
	      TransitionFade::create(2.0f, PlayScene::create()));
}

void playLayer::getProps(Ref* pSender)
{
	pboxMenu1->setVisible(false);
	prop* props1 = prop::createWithFileName("red.png");
	prop* props2 = prop::createWithFileName("blue.png");
	switch (rand() % 2)
	{
	case 0:
		props = props2;
		props->setPosition(pboxMenu1->getPosition().x+80, pboxMenu1->getPosition().y);
		this->addChild(props, 2);
		props->setPropData(0);
		/*props->useProp(knight);*/

	case 1:
		props = props1;
		props->setPosition(pboxMenu1->getPosition().x+80, pboxMenu1->getPosition().y);
		this->addChild(props, 2);
		props->setPropData(1);
		props->useProp(knight);
	}
}


void playLayer::menuPauseCallback(Ref* pSender)
{

	//获得当前窗口的大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	Scene *scene = Director::getInstance()->getRunningScene();
	
	//遍历当前类的所有子节点信息，画入renderTexture中
	renderTexture->begin();
	this->visit();
	renderTexture->end();

	//将游戏界面暂停，压入场景堆栈 并切换到GamePause界面
	Director::getInstance()->pushScene(gamePause::scene(renderTexture));
}


void playLayer::menuSetCallback(Ref* pSender)
{
	CCScheduler* defaultScheduler = CCDirector::sharedDirector()->getScheduler();
	defaultScheduler->pauseTarget(this);
	Director::getInstance()->pushScene(TransitionFade::create(1.0f, SetWorld::createScene()));
	defaultScheduler->resumeTarget(this);
}


void playLayer::setViewPointCenter(Point position)
{
	auto winSize = Director::getInstance()->getWinSize();


	int x = MAX(position.x, winSize.width / 2);
	int y = MAX(position.y, winSize.height / 2);
	x = MIN(x, (map->getMapSize().width * this->map->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (map->getMapSize().height * map->getTileSize().height) - winSize.height / 2);
	auto actualPosition = Point(x, y);

	auto centerOfView = Point(winSize.width / 2, winSize.height / 2);
	auto viewPoint = centerOfView - actualPosition;
	this->setPosition(viewPoint);
}


Point playLayer::tileToWin(Point position)
{
	int x = position.x / map->getTileSize().width ;
	int y =(map->getTileSize().height * map->getMapSize().height - position.y) / map->getTileSize().height;
	return Point(x, y);
}


Point playLayer::winToTile(Point position)
{
	int x = position.x * map->getTileSize().width;
	int y = (map->getTileSize().height * map->getMapSize().height - position.y) * map->getTileSize().height;
	return Point(x, y);
}

bool playLayer::isTileBlocked(Point position)
{
	Point tilePos = tileToWin(position);
	int tileGID = block->tileGIDAt(tilePos);

	if (tileGID != 0)
	{
		auto properties = map->getPropertiesForGID(tileGID).asValueMap();
		if (!properties.empty())
		{
			auto canMove = properties["unblocked"].asString();
			if ("true" == canMove)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
    }
}


void playLayer::update(float delta)
{
	knight->update(delta);
	this->updatePosition();
}

void playLayer::updatePosition()
{
	float x, y;
	if (isTileBlocked(Point(knight->getDesiredPosition().x, knight->getDesiredPosition().y)))
	{
		x = knight->getDesiredPosition().x - 20*_direction.x;
		y= knight->getDesiredPosition().y -20*_direction.y;
	}
	else
	{
		x = knight->getDesiredPosition().x ;
		y = knight->getDesiredPosition().y ;
	}

	knight->setPosition(Point(x, y));
	this->setViewPointCenter(knight->getPosition());

	/*bloodView->setPosition(Vec2(knight->getPosition().x, knight->getPosition().y + 20));*/
}

void playLayer::didChangeDirectionTo(cocos2d::CCPoint direction)
{
	float x = direction.x;
	float y = direction.y;
	knight->walkWithDirection(direction);
	_direction.x = x;
	_direction.y = y;
}

void playLayer::isHoldingDirection(cocos2d::CCPoint direction)
{
	knight->walkWithDirection(direction);
}



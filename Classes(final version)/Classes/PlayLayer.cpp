#include "cocos2d.h"
#include"PlayLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"gamePause.h"
#include"SetScene.h"
#include<ctime>
#include"SimpleAudioEngine.h"
#include"safemap.h"
#include"backpack.h"
USING_NS_CC;


bool playLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}


	//子弹初始化
	witcherbullet1U = Enemywitcherbullet::createbullet();
	witcherbullet1R = Enemywitcherbullet::createbullet();
	witcherbullet1L = Enemywitcherbullet::createbullet();
	witcherbullet1D = Enemywitcherbullet::createbullet();

	witcherbullet5U = Enemywitcherbullet::createbullet();
	witcherbullet5R = Enemywitcherbullet::createbullet();
	witcherbullet5L = Enemywitcherbullet::createbullet();
	witcherbullet5D = Enemywitcherbullet::createbullet();

	witcherbullet10U = Enemywitcherbullet::createbullet();
	witcherbullet10R = Enemywitcherbullet::createbullet();
	witcherbullet10L = Enemywitcherbullet::createbullet();
	witcherbullet10D = Enemywitcherbullet::createbullet();

	witcherbullet13U = Enemywitcherbullet::createbullet();
	witcherbullet13R = Enemywitcherbullet::createbullet();
	witcherbullet13L = Enemywitcherbullet::createbullet();
	witcherbullet13D = Enemywitcherbullet::createbullet();


	witcherbullet18U = Enemywitcherbullet::createbullet();
	witcherbullet18R = Enemywitcherbullet::createbullet();
	witcherbullet18L = Enemywitcherbullet::createbullet();
	witcherbullet18D = Enemywitcherbullet::createbullet();

	shooterbullet2 = Enemyshooterbullet::createbullet();
	shooterbullet6 = Enemyshooterbullet::createbullet();
	shooterbullet8 = Enemyshooterbullet::createbullet();
	shooterbullet9 = Enemyshooterbullet::createbullet();
	shooterbullet12 = Enemyshooterbullet::createbullet();
	shooterbullet17 = Enemyshooterbullet::createbullet();


	bossbullet7U = Enemybossbullet::createbullet();
	bossbullet7R = Enemybossbullet::createbullet();
	bossbullet7L = Enemybossbullet::createbullet();
	bossbullet7D = Enemybossbullet::createbullet();

	bossbullet14U = Enemybossbullet::createbullet();
	bossbullet14R = Enemybossbullet::createbullet();
	bossbullet14L = Enemybossbullet::createbullet();
	bossbullet14D = Enemybossbullet::createbullet();

	bossbullet15U = Enemybossbullet::createbullet();
	bossbullet15R = Enemybossbullet::createbullet();
	bossbullet15L = Enemybossbullet::createbullet();
	bossbullet15D = Enemybossbullet::createbullet();

	bossbullet16U = Enemybossbullet::createbullet();
	bossbullet16R = Enemybossbullet::createbullet();
	bossbullet16L = Enemybossbullet::createbullet();
	bossbullet16D = Enemybossbullet::createbullet();

	initMap();
	initHero();
	initNextLevelRoom();
	this->scheduleUpdate();
	auto visibleSize = Director::getInstance()->getVisibleSize();

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


	//设想这个宝箱出武器
	auto boxItem2 = MenuItemImage::create(
		"baoxiang.png",
		"baoxiang.png",
		this,
		menu_selector(playLayer::getWeapon));

	pboxMenu2 = CCMenu::create(boxItem2, NULL);
	auto boxShowUpPoint2 = objects->getObject("baoxiang2");

	int i = boxShowUpPoint2["x"].asInt();
	int j = boxShowUpPoint2["y"].asInt();
	pboxMenu2->setPosition(Vec2(i, j));
	pboxMenu2->setScale(0.6f);
	this->addChild(pboxMenu2, 1);


	//设想这个宝箱出武器
	auto boxItem3 = MenuItemImage::create(
		"baoxiang.png",
		"baoxiang.png",
		this,
		menu_selector(playLayer::getProps));

	pboxMenu3 = CCMenu::create(boxItem3, NULL);
	auto boxShowUpPoint3 = objects->getObject("baoxiang3");

	i = boxShowUpPoint3["x"].asInt();
	j = boxShowUpPoint3["y"].asInt();
	pboxMenu3->setPosition(Vec2(i, j));
	pboxMenu3->setScale(0.6f);
	this->addChild(pboxMenu3, 1);


	//游戏暂停菜单
	auto pCloseItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(playLayer::menuPauseCallback));

	pMenu1 = CCMenu::create(pCloseItem, NULL);
	pMenu1->setPosition(knight->getPosition().x + 300, knight->getPosition().y + 100);
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
	this->addChild(pMenu2, 1);

	auto* pbag = MenuItemImage::create("backpack.jpg", "backpack.jpg", this, menu_selector(playLayer::bag));
	m_bag = Menu::create(pbag, NULL, NULL);
	m_bag->setScale(0.2);
	m_bag->setAnchorPoint(Vec2::ZERO);
	m_bag->setPosition(knight->getPosition().x + 300, knight->getPosition().y + 150);
	addChild(m_bag, 1, "bag");


	if (mapType == 1)
	{
		this->schedule(schedule_selector(playLayer::EnemymakeAttackation1), 2.0f);
	}
	else
	{
		this->schedule(schedule_selector(playLayer::EnemymakeAttackation2), 2.0f);
	}

	return true;
}


void playLayer::initMap()
{
	auto *recMap1 = TMXTiledMap::create("map1.tmx");
	auto *recMap2 = TMXTiledMap::create("QishiMap.tmx");

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	srand(time(0));
	switch (rand() % 3)
	{
	case 0:
		map = recMap1;
		recMap1->setAnchorPoint(Vec2(0, 0));
		recMap1->setPosition(origin);
		this->addChild(recMap1, -1);

		initMonster9();
		initMonster10();
		initMonster11();
		initMonster12();
		initMonster13();
		initMonster14();
		initMonster15();
		initMonster16();

		mapType = 2;
		break;

	default:
		map = recMap2;
		recMap2->setAnchorPoint(Vec2(0, 0));
		recMap2->setPosition(origin);
		this->addChild(recMap2, -1);

		initMonster1();
		initMonster2();
		initMonster3();
		initMonster4();
		initMonster5();
		initMonster6();
		initMonster7();
		initMonster8();
		initMonster17();
		initMonster18();

		mapType = 1;
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
	knight->setCurrentBlood(100);

	knight->setPosition(Point(x, y));
	knight->setScale(0.6f);
	this->addChild(knight, 0);
	knight->setWalkSpeed(200.0);
	currentWeapon = knight->getWeapon();
	currentWeapon->setAnchorPoint(Vec2(0.6f, 0.6f));
	vecWeapon.pushBack(currentWeapon);

	bullet = Bullet::createbullet();

	safemap::myBag.setHero(knight);
	this->addChild(bullet, 0);
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
	pMenu->setPosition(Vec2(x, y));
	this->addChild(pMenu, 1);
}

void playLayer::initMonster1()//创建怪物1
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster1");
	auto monster1ShowUpPoint = objects->getObject("monster1Born");
	int x = monster1ShowUpPoint["x"].asInt();
	int y = monster1ShowUpPoint["y"].asInt();
	monster1 = Monsterwitcher::createWithFileName("monsterwitcher.png");
	monster1->initMonsterwitcherSprite("bloodOutside.jpg", "blood.jpg");
	monster1->setCurrentBlood(100);
	monster1->setPosition(Point(x, y));
	monster1->setScale(0.6f);
	auto moveBy1 = MoveBy::create(2, Vec2(50, 10));
	auto moveBy2 = MoveBy::create(2, Vec2(-50, -10));
	auto seq = Sequence::create(moveBy1, moveBy2, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster1->runAction(repeatforever);
	this->addChild(monster1, 0);

	vecMonster.pushBack(monster1);
	//所有子弹初始化

	monster1->bulletU = witcherbullet1U;
	this->addChild(monster1->bulletU, 1);
	monster1->bulletD = witcherbullet1D;
	this->addChild(monster1->bulletD, 1);
	monster1->bulletL = witcherbullet1L;
	this->addChild(monster1->bulletL, 1);
	monster1->bulletR = witcherbullet1R;
	this->addChild(monster1->bulletR, 1);

	//判断怪物死亡
	if (monster1->getCurrentBlood() == 0)
	{
		removeChild(monster1, TRUE);
	}

}
void playLayer::initMonster2()//创建怪物2
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster2");
	auto monster2ShowUpPoint = objects->getObject("monster2Born");
	int x = monster2ShowUpPoint["x"].asInt();
	int y = monster2ShowUpPoint["y"].asInt();
	monster2 = Monstershooter::createWithFileName("monstershooter.png");
	monster2->initMonstershooterSprite("bloodOutside.jpg", "blood.jpg");
	monster2->setCurrentBlood(100);
	monster2->setPosition(Point(x, y));
	monster2->setScale(0.6f);
	this->addChild(monster2, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-40, -30));
	auto moveBy2 = MoveBy::create(2, Vec2(40, 30));
	auto seq = Sequence::create(moveBy1, moveBy2, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster2->runAction(repeatforever);

	vecMonster.pushBack(monster2);
	monster2->bullet = shooterbullet2;
	this->addChild(monster2->bullet, 1);
	//判断怪物死亡
	if (monster2->getCurrentBlood() == 0)
	{
		removeChild(monster2, TRUE);
	}
}


void playLayer::initMonster3()//创建怪物3
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster3");
	auto monster3ShowUpPoint = objects->getObject("monster3Born");
	int x = monster3ShowUpPoint["x"].asInt();
	int y = monster3ShowUpPoint["y"].asInt();
	monster3 = Monster::createWithFileName("monster.png");
	monster3->initMonsterSprite("bloodOutside.jpg", "blood.jpg");
	monster3->setCurrentBlood(80);
	monster3->setPosition(Point(x, y));
	monster3->setScale(0.6f);
	this->addChild(monster3, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(60, 20));
	auto moveBy2 = MoveBy::create(2, Vec2(-60, -20));
	auto seq = Sequence::create(moveBy1, moveBy2, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster3->runAction(repeatforever);

	vecMonster.pushBack(monster3);
	//判断怪物死亡
	if (monster3->getCurrentBlood() == 0)
	{
		removeChild(monster3, TRUE);
	}

}

void playLayer::initMonster4()//创建怪物4
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster4");
	auto monster4ShowUpPoint = objects->getObject("monster4Born");
	int x = monster4ShowUpPoint["x"].asInt();
	int y = monster4ShowUpPoint["y"].asInt();
	monster4 = Monster::createWithFileName("monster.png");
	monster4->initMonsterSprite("bloodOutside.jpg", "blood.jpg");
	monster4->setCurrentBlood(80);
	monster4->setPosition(Point(x, y));
	monster4->setScale(0.6f);
	this->addChild(monster4, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(30, 20));
	auto moveBy2 = MoveBy::create(2, Vec2(-30, -20));
	auto seq = Sequence::create(moveBy1, moveBy2, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster4->runAction(repeatforever);

	vecMonster.pushBack(monster4);
	//判断怪物死亡
	if (monster4->getCurrentBlood() == 0)
	{
		removeChild(monster4, TRUE);
	}
}

void playLayer::initMonster5()//创建怪物5
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster5");
	auto monster5ShowUpPoint = objects->getObject("monster5Born");
	int x = monster5ShowUpPoint["x"].asInt();
	int y = monster5ShowUpPoint["y"].asInt();
	monster5 = Monsterwitcher::createWithFileName("monsterwitcher.png");
	monster5->initMonsterwitcherSprite("bloodOutside.jpg", "blood.jpg");
	monster5->setCurrentBlood(350);
	monster5->setPosition(Point(x, y));
	monster5->setScale(0.6f);
	this->addChild(monster5, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-20, 20));
	auto moveBy2 = MoveBy::create(2, Vec2(20, -20));
	auto seq = Sequence::create(moveBy1, moveBy2, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster5->runAction(repeatforever);

	vecMonster.pushBack(monster5);
	monster5->bulletU = witcherbullet5U;
	this->addChild(monster5->bulletU, 1);
	monster5->bulletD = witcherbullet5D;
	this->addChild(monster5->bulletD, 1);
	monster5->bulletL = witcherbullet5L;
	this->addChild(monster5->bulletL, 1);
	monster5->bulletR = witcherbullet5R;
	this->addChild(monster5->bulletR, 1);
	//判断怪物死亡
	if (monster5->getCurrentBlood() == 0)
	{
		removeChild(monster5, TRUE);
	}
}
void playLayer::initMonster6()//创建怪物6
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster6");
	auto monster6ShowUpPoint = objects->getObject("monster6Born");
	int x = monster6ShowUpPoint["x"].asInt();
	int y = monster6ShowUpPoint["y"].asInt();
	monster6 = Monstershooter::createWithFileName("monstershooter.png");
	monster6->initMonstershooterSprite("bloodOutside.jpg", "blood.jpg");
	monster6->setCurrentBlood(100);
	monster6->setPosition(Point(x, y));
	monster6->setScale(0.6f);
	this->addChild(monster6, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(20, -10));
	auto moveBy2 = MoveBy::create(2, Vec2(-20, 10));
	auto moveBy3 = MoveBy::create(2, Vec2(10, 5));
	auto moveBy4 = MoveBy::create(2, Vec2(-10, -5));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster6->runAction(repeatforever);

	vecMonster.pushBack(monster6);
	monster6->bullet = shooterbullet6;
	this->addChild(monster6->bullet, 1);

	//判断怪物死亡
	if (monster6->getCurrentBlood() == 0)
	{
		removeChild(monster6, TRUE);
	}
}
void playLayer::initMonster7()//创建怪物7
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster7");
	auto monster7ShowUpPoint = objects->getObject("monster7Born");
	int x = monster7ShowUpPoint["x"].asInt();
	int y = monster7ShowUpPoint["y"].asInt();
	monster7 = Monsterwitcherboss::createWithFileName("monsterwitcher.png");
	monster7->initMonsterwitcherbossSprite("bloodOutside.jpg", "blood.jpg");
	monster7->setCurrentBlood(350);
	monster7->setPosition(Point(x, y));
	monster7->setScale(2.0f);
	this->addChild(monster7, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(30, 20));
	auto moveBy2 = MoveBy::create(2, Vec2(-30, -20));
	auto moveBy3 = MoveBy::create(2, Vec2(20, 10));
	auto moveBy4 = MoveBy::create(2, Vec2(-20, -10));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster7->runAction(repeatforever);

	vecMonster.pushBack(monster7);
	monster7->bulletU = bossbullet7U;
	this->addChild(monster7->bulletU, 1);
	monster7->bulletD = bossbullet7D;
	this->addChild(monster7->bulletD, 1);
	monster7->bulletL = bossbullet7L;
	this->addChild(monster7->bulletL, 1);
	monster7->bulletR = bossbullet7R;
	this->addChild(monster7->bulletR, 1);

	//判断怪物死亡
	if (monster7->getCurrentBlood() == 0)
	{
		removeChild(monster7, TRUE);
	}
}
void playLayer::initMonster8()//创建怪物8
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster8");
	auto monster8ShowUpPoint = objects->getObject("monster8Born");
	int x = monster8ShowUpPoint["x"].asInt();
	int y = monster8ShowUpPoint["y"].asInt();
	monster8 = Monstershooter::createWithFileName("monstershooter.png");
	monster8->initMonstershooterSprite("bloodOutside.jpg", "blood.jpg");
	monster8->setCurrentBlood(100);
	monster8->setPosition(Point(x, y));
	monster8->setScale(0.6f);
	this->addChild(monster8, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(30, 20));
	auto moveBy2 = MoveBy::create(2, Vec2(-30, -20));
	auto moveBy3 = MoveBy::create(2, Vec2(20, 10));
	auto moveBy4 = MoveBy::create(2, Vec2(-20, -10));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster8->runAction(repeatforever);

	vecMonster.pushBack(monster8);
	monster8->bullet = shooterbullet8;
	this->addChild(monster8->bullet, 1);

	//判断怪物死亡
	if (monster8->getCurrentBlood() == 0)
	{
		removeChild(monster8, TRUE);
	}
}


void playLayer::initMonster9()//创建怪物9
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster9");
	auto monster9ShowUpPoint = objects->getObject("monster9Born");
	int x = monster9ShowUpPoint["x"].asInt();
	int y = monster9ShowUpPoint["y"].asInt();
	monster9 = Monstershooter::createWithFileName("monstershooter.png");
	monster9->initMonstershooterSprite("bloodOutside.jpg", "blood.jpg");
	monster9->setCurrentBlood(100);
	monster9->setPosition(Point(x, y));
	monster9->setScale(0.6f);
	this->addChild(monster9, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(50, 20));
	auto moveBy2 = MoveBy::create(2, Vec2(-50, -20));
	auto moveBy3 = MoveBy::create(2, Vec2(20, 30));
	auto moveBy4 = MoveBy::create(2, Vec2(-20, -30));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster9->runAction(repeatforever);

	vecMonster.pushBack(monster9);
	monster9->bullet = shooterbullet9;
	this->addChild(monster9->bullet, 1);


	//判断怪物死亡
	if (monster9->getCurrentBlood() == 0)
	{
		removeChild(monster9, TRUE);
	}
}

void playLayer::initMonster10()//创建怪物10
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster10");
	auto monster10ShowUpPoint = objects->getObject("monster10Born");
	int x = monster10ShowUpPoint["x"].asInt();
	int y = monster10ShowUpPoint["y"].asInt();
	monster10 = Monsterwitcher::createWithFileName("monsterwitcher.png");
	monster10->initMonsterwitcherSprite("bloodOutside.jpg", "blood.jpg");
	monster10->setCurrentBlood(100);
	monster10->setPosition(Point(x, y));
	monster10->setScale(0.6f);
	this->addChild(monster10, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-5, -5));
	auto moveBy2 = MoveBy::create(2, Vec2(5, 5));
	auto moveBy3 = MoveBy::create(2, Vec2(10, 10));
	auto moveBy4 = MoveBy::create(2, Vec2(-10, -10));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster10->runAction(repeatforever);

	vecMonster.pushBack(monster10);

	monster10->bulletU = witcherbullet10U;
	this->addChild(monster10->bulletU, 1);
	monster10->bulletD = witcherbullet10D;
	this->addChild(monster10->bulletD, 1);
	monster10->bulletL = witcherbullet10L;
	this->addChild(monster10->bulletL, 1);
	monster10->bulletR = witcherbullet10R;
	this->addChild(monster10->bulletR, 1);
	//判断怪物死亡
	if (monster10->getCurrentBlood() == 0)
	{
		removeChild(monster10, TRUE);
	}
}

void playLayer::initMonster11()//创建怪物11
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster11");
	auto monster11ShowUpPoint = objects->getObject("monster11Born");
	int x = monster11ShowUpPoint["x"].asInt();
	int y = monster11ShowUpPoint["y"].asInt();
	monster11 = Monster::createWithFileName("monster1.png");
	monster11->initMonsterSprite("bloodOutside.jpg", "blood.jpg");
	monster11->setCurrentBlood(60);
	monster11->setPosition(Point(x, y));
	monster11->setScale(0.6f);
	this->addChild(monster11, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-20, -20));
	auto moveBy2 = MoveBy::create(2, Vec2(30, 40));
	auto moveBy3 = MoveBy::create(2, Vec2(30, -50));
	auto moveBy4 = MoveBy::create(2, Vec2(-40, -30));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster11->runAction(repeatforever);

	vecMonster.pushBack(monster11);
	//判断怪物死亡
	if (monster11->getCurrentBlood() == 0)
	{
		removeChild(monster11, TRUE);
	}
}

void playLayer::initMonster12()//创建怪物12
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster12");
	auto monster12ShowUpPoint = objects->getObject("monster12Born");
	int x = monster12ShowUpPoint["x"].asInt();
	int y = monster12ShowUpPoint["y"].asInt();
	monster12 = Monstershooter::createWithFileName("monstershooter.png");
	monster12->initMonstershooterSprite("bloodOutside.jpg", "blood.jpg");
	monster12->setCurrentBlood(100);
	monster12->setPosition(Point(x, y));
	monster12->setScale(0.6f);
	this->addChild(monster12, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-20, -20));
	auto moveBy2 = MoveBy::create(2, Vec2(30, 40));
	auto moveBy3 = MoveBy::create(2, Vec2(30, -50));
	auto moveBy4 = MoveBy::create(2, Vec2(-40, -30));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster12->runAction(repeatforever);

	vecMonster.pushBack(monster12);

	monster12->bullet = shooterbullet12;
	this->addChild(monster12->bullet, 1);
	//判断怪物死亡
	if (monster12->getCurrentBlood() == 0)
	{
		removeChild(monster12, TRUE);
	}
}

void playLayer::initMonster13()//创建怪物13
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster13");
	auto monster13ShowUpPoint = objects->getObject("monster13Born");
	int x = monster13ShowUpPoint["x"].asInt();
	int y = monster13ShowUpPoint["y"].asInt();
	monster13 = Monsterwitcher::createWithFileName("monstershooter.png");
	monster13->initMonsterwitcherSprite("bloodOutside.jpg", "blood.jpg");
	monster13->setCurrentBlood(100);
	monster13->setPosition(Point(x, y));
	monster13->setScale(0.6f);
	this->addChild(monster13, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-8, -8));
	auto moveBy2 = MoveBy::create(2, Vec2(5, 10));
	auto moveBy3 = MoveBy::create(2, Vec2(5, -10));
	auto moveBy4 = MoveBy::create(2, Vec2(-2, 8));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster13->runAction(repeatforever);

	vecMonster.pushBack(monster13);

	monster13->bulletU = witcherbullet13U;
	this->addChild(monster13->bulletU, 1);
	monster13->bulletD = witcherbullet13D;
	this->addChild(monster13->bulletD, 1);
	monster13->bulletL = witcherbullet13L;
	this->addChild(monster13->bulletL, 1);
	monster13->bulletR = witcherbullet13R;
	this->addChild(monster13->bulletR, 1);
	//判断怪物死亡
	if (monster13->getCurrentBlood() == 0)
	{
		removeChild(monster13, TRUE);
	}
}

void playLayer::initMonster14()//创建怪物14
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster14");
	auto monster14ShowUpPoint = objects->getObject("monster14Born");
	int x = monster14ShowUpPoint["x"].asInt();
	int y = monster14ShowUpPoint["y"].asInt();
	monster14 = Monsterwitcherboss::createWithFileName("monsterwitcher.png");
	monster14->initMonsterwitcherbossSprite("bloodOutside.jpg", "blood.jpg");
	monster14->setCurrentBlood(350);
	monster14->setPosition(Point(x, y));
	monster14->setScale(2.0f);
	this->addChild(monster14, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-25, -20));
	auto moveBy2 = MoveBy::create(2, Vec2(20, 10));
	auto moveBy3 = MoveBy::create(2, Vec2(35, -20));
	auto moveBy4 = MoveBy::create(2, Vec2(-30, 30));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster14->runAction(repeatforever);

	vecMonster.pushBack(monster14);

	monster14->bulletU = bossbullet14U;
	this->addChild(monster14->bulletU, 1);
	monster14->bulletD = bossbullet14D;
	this->addChild(monster14->bulletD, 1);
	monster14->bulletL = bossbullet14L;
	this->addChild(monster14->bulletL, 1);
	monster14->bulletR = bossbullet14R;
	this->addChild(monster14->bulletR, 1);
	//判断怪物死亡
	if (monster14->getCurrentBlood() == 0)
	{
		removeChild(monster14, TRUE);
	}
}

void playLayer::initMonster15()//创建怪物15
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster15");
	auto monster15ShowUpPoint = objects->getObject("monster15Born");
	int x = monster15ShowUpPoint["x"].asInt();
	int y = monster15ShowUpPoint["y"].asInt();
	monster15 = Monsterwitcherboss::createWithFileName("monsterwitcher.png");
	monster15->initMonsterwitcherbossSprite("bloodOutside.jpg", "blood.jpg");
	monster15->setCurrentBlood(350);
	monster15->setPosition(Point(x, y));
	monster15->setScale(2.0f);
	this->addChild(monster15, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(25, 15));
	auto moveBy2 = MoveBy::create(2, Vec2(-20, -10));
	auto moveBy3 = MoveBy::create(2, Vec2(-35, 15));
	auto moveBy4 = MoveBy::create(2, Vec2(30, -20));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster15->runAction(repeatforever);

	vecMonster.pushBack(monster15);

	monster15->bulletU = bossbullet15U;
	this->addChild(monster15->bulletU, 1);
	monster15->bulletD = bossbullet15D;
	this->addChild(monster15->bulletD, 1);
	monster15->bulletL = bossbullet15L;
	this->addChild(monster15->bulletL, 1);
	monster15->bulletR = bossbullet15R;
	this->addChild(monster15->bulletR, 1);
	//判断怪物死亡
	if (monster15->getCurrentBlood() == 0)
	{
		removeChild(monster15, TRUE);
	}
}


void playLayer::initMonster16()//创建怪物16
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster16");
	auto monster16ShowUpPoint = objects->getObject("monster16Born");
	int x = monster16ShowUpPoint["x"].asInt();
	int y = monster16ShowUpPoint["y"].asInt();
	monster16 = Monsterwitcherboss::createWithFileName("monsterwitcher.png");
	monster16->initMonsterwitcherbossSprite("bloodOutside.jpg", "blood.jpg");
	monster16->setCurrentBlood(350);
	monster16->setPosition(Point(x, y));
	monster16->setScale(2.0f);
	this->addChild(monster16, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(30, -20));
	auto moveBy2 = MoveBy::create(2, Vec2(-20, 10));
	auto moveBy3 = MoveBy::create(2, Vec2(25, -20));
	auto moveBy4 = MoveBy::create(2, Vec2(-30, 30));
	auto seq = Sequence::create(moveBy1, moveBy2, moveBy3, moveBy4, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster16->runAction(repeatforever);
	vecMonster.pushBack(monster16);

	monster16->bulletU = bossbullet16U;
	this->addChild(monster16->bulletU, 1);
	monster16->bulletD = bossbullet16D;
	this->addChild(monster16->bulletD, 1);
	monster16->bulletL = bossbullet16R;
	this->addChild(monster16->bulletL, 1);
	monster16->bulletR = bossbullet16L;
	this->addChild(monster16->bulletR, 1);
	//判断怪物死亡
	if (monster16->getCurrentBlood() == 0)
	{
		removeChild(monster16, TRUE);
	}
}


void playLayer::initMonster17()//创建怪物17
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster17");
	auto monster17ShowUpPoint = objects->getObject("monster17Born");
	int x = monster17ShowUpPoint["x"].asInt();
	int y = monster17ShowUpPoint["y"].asInt();
	monster17 = Monstershooter::createWithFileName("monstershooter.png");
	monster17->initMonstershooterSprite("bloodOutside.jpg", "blood.jpg");
	monster17->setCurrentBlood(100);
	monster17->setPosition(Point(x, y));
	monster17->setScale(0.6f);
	this->addChild(monster17, 0);
	auto moveBy1 = MoveBy::create(2, Vec2(-40, -30));
	auto moveBy2 = MoveBy::create(2, Vec2(40, 30));
	auto seq = Sequence::create(moveBy1, moveBy2, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster17->runAction(repeatforever);

	vecMonster.pushBack(monster17);
	monster17->bullet = shooterbullet17;
	this->addChild(monster17->bullet, 1);
	//判断怪物死亡
	if (monster17->getCurrentBlood() == 0)
	{
		removeChild(monster17, TRUE);
	}
}

void playLayer::initMonster18()//创建怪物18
{

	TMXObjectGroup* objects = map->objectGroupNamed("monster18");
	auto monster18ShowUpPoint = objects->getObject("monster18Born");
	int x = monster18ShowUpPoint["x"].asInt();
	int y = monster18ShowUpPoint["y"].asInt();
	monster18 = Monsterwitcher::createWithFileName("monsterwitcher.png");
	monster18->initMonsterwitcherSprite("bloodOutside.jpg", "blood.jpg");
	monster18->setCurrentBlood(100);
	monster18->setPosition(Point(x, y));
	monster18->setScale(0.6f);
	auto moveBy1 = MoveBy::create(2, Vec2(50, 10));
	auto moveBy2 = MoveBy::create(2, Vec2(-50, -10));
	auto seq = Sequence::create(moveBy1, moveBy2, nullptr);
	RepeatForever* repeatforever = RepeatForever::create(seq);
	monster18->runAction(repeatforever);
	this->addChild(monster18, 0);

	vecMonster.pushBack(monster18);
	//所有子弹初始化

	monster18->bulletU = witcherbullet18U;
	this->addChild(monster18->bulletU, 1);
	monster18->bulletD = witcherbullet18D;
	this->addChild(monster18->bulletD, 1);
	monster18->bulletL = witcherbullet18L;
	this->addChild(monster18->bulletL, 1);
	monster18->bulletR = witcherbullet18R;
	this->addChild(monster18->bulletR, 1);

	//判断怪物死亡
	if (monster18->getCurrentBlood() == 0)
	{
		removeChild(monster18, TRUE);
	}

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
	Director::getInstance()->replaceScene(TransitionFade::create(2.0f, PlayScene::create()));
}


Vector<weapon*>& playLayer::getWeaponVec()
{
	return this->vecWeapon;
}

void playLayer::getWeapon(Ref* pSender)
{
	//播放音效
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("buttom.mp3");

	pboxMenu2->setVisible(false);
	weapon *newWeapon = NULL;

	srand(time(0));
	switch (rand() % 3)
	{
	case 0:
		newWeapon = weapon::createWithFileName("weapon1.png");
		newWeapon->setAttack(20);
		newWeapon->setExpData(2);
		newWeapon->setWeaponType(1);
		break;

	case 1:
		newWeapon = weapon::createWithFileName("weapon2.png");
		newWeapon->setAttack(30);
		newWeapon->setExpData(3);
		newWeapon->setWeaponType(1);
		break;

	case 2:

		newWeapon = weapon::createWithFileName("knife.png");
		newWeapon->setAttack(10);
		newWeapon->setExpData(0);
		newWeapon->setWeaponType(2);
		break;

	}
	knight->setWeapon(newWeapon);
	this->vecWeapon.pushBack(newWeapon);
	this->currentWeapon = newWeapon;
	currentWeapon->setAnchorPoint(Vec2(0.6f, 0.6f));
	CCLOG("vecWeapon Size:%d", vecWeapon.size());
}

void playLayer::getProps(Ref* pSender)
{
	this->boxNum++;
	if (boxNum == 1)
	{
		pboxMenu1->setVisible(false);
	}

	if (boxNum == 2)
	{
		pboxMenu3->setVisible(false);
	}
	prop* props1 = prop::createWithFileName("red.png");
	prop* props2 = prop::createWithFileName("blue.png");

	//播放音效
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("buttom.mp3");

	srand(time(0));
	switch (rand() % 3)
	{
	case 0:
		props = props2;
		props->setPosition(knight->getPosition().x + 20, knight->getPosition().y);
		this->addChild(props, 2);
		props->setPropData(1);
		props->useProp(knight);

	default:
		props = props1;
		props->setPosition(knight->getPosition().x + 20, knight->getPosition().y);
		this->addChild(props, 2);
		props->setPropData(0);
		props->useProp(knight);
	}
}


void playLayer::bag(Ref* pSender)
{
	Director::sharedDirector()->pushScene(safemap::myBag.createScene());
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
	int x = position.x / map->getTileSize().width;
	int y = (map->getTileSize().height * map->getMapSize().height - position.y) / map->getTileSize().height;
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
		x = knight->getDesiredPosition().x - 20 * _direction.x;
		y = knight->getDesiredPosition().y - 20 * _direction.y;
	}
	else
	{
		x = knight->getDesiredPosition().x;
		y = knight->getDesiredPosition().y;
	}

	knight->setPosition(Point(x, y));
	m_bag->setPosition(Vec2(knight->getPosition().x + 200, knight->getPosition().y - 200));

	this->setViewPointCenter(knight->getPosition());

}

void playLayer::didChangeDirectionTo(cocos2d::CCPoint direction)
{
	float x = direction.x;
	float y = direction.y;
	knight->walkWithDirection(direction);
	currentWeapon->RotateWhileWalk(direction);
	_direction.x = x;
	_direction.y = y;
}

void playLayer::isHoldingDirection(cocos2d::CCPoint direction)
{
	float x = direction.x;
	float y = direction.y;
	if (x == 0 && y == 0)
	{
		changeWeapon();
	}
	else
	{
		this->schedule(schedule_selector(playLayer::makeAttackation), 0.5, 0, 0.1);
	}

}

void playLayer::changeWeapon()
{
	//播放音效
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("changeWeapon.mp3");

	if (this->vecWeapon.size() != 0)
	{
		for (auto i : vecWeapon)
		{
			if (i != currentWeapon)
			{
				knight->setWeapon(i);
				this->currentWeapon = i;
				break;
			}
		}
	}

	CCLOG("vecWeapon Size:%d", vecWeapon.size());
}

void playLayer::makeAttackation(float delta)
{
	Entity *aim = NULL;
	for (auto i : vecMonster)
	{
		if (i->getCurrentBlood() <= 0)
		{
			i->died();
			removeChild(i, TRUE);
			continue;
		}
		else
		{
			aim = i;
			break;
		}
	}
	if (aim == NULL)
	{
		bullet->setVisible(false);
		currentWeapon->rotateBack();
	}
	else
	{
		if (currentWeapon->getWeaponType() == 2)
		{
			currentWeapon->isCollision(knight,aim);
		}
		else
		{
			//播放音效
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("shoot.mp3");

			currentWeapon->makeRotate(knight, aim);
			bullet->addNewBullet(knight);//如果不行就换成坐标
			bullet->moveBullet(knight, aim, currentWeapon->getAttack(), knight->exp, currentWeapon);
		}
	}
}

void playLayer::EnemymakeAttackation1(float delta)
{

	monster2->bullet->addNewBullet(monster2);//如果不行就换成坐标
	monster2->bullet->moveBullet(monster2, knight);

	monster6->bullet->addNewBullet(monster6);//如果不行就换成坐标
	monster6->bullet->moveBullet(monster6, knight);

	monster8->bullet->addNewBullet(monster8);//如果不行就换成坐标
	monster8->bullet->moveBullet(monster8, knight);

	monster17->bullet->addNewBullet(monster17);//如果不行就换成坐标
	monster17->bullet->moveBullet(monster17, knight);

	monster1->bulletR->addNewBullet(monster1);//如果不行就换成坐标
	monster1->bulletR->moveBullet1(monster1, knight);
	monster1->bulletU->addNewBullet(monster1);//如果不行就换成坐标
	monster1->bulletU->moveBullet2(monster1, knight);
	monster1->bulletL->addNewBullet(monster1);//如果不行就换成坐标
	monster1->bulletL->moveBullet3(monster1, knight);
	monster1->bulletD->addNewBullet(monster1);//如果不行就换成坐标
	monster1->bulletD->moveBullet4(monster1, knight);


	monster5->bulletR->addNewBullet(monster5);//如果不行就换成坐标
	monster5->bulletR->moveBullet1(monster5, knight);
	monster5->bulletU->addNewBullet(monster5);//如果不行就换成坐标
	monster5->bulletU->moveBullet2(monster5, knight);
	monster5->bulletL->addNewBullet(monster5);//如果不行就换成坐标
	monster5->bulletL->moveBullet3(monster5, knight);
	monster5->bulletD->addNewBullet(monster5);//如果不行就换成坐标
	monster5->bulletD->moveBullet4(monster5, knight);

	monster7->bulletR->addNewBullet(monster7);//如果不行就换成坐标
	monster7->bulletR->moveBullet1(monster7, knight);
	monster7->bulletU->addNewBullet(monster7);//如果不行就换成坐标
	monster7->bulletU->moveBullet2(monster7, knight);
	monster7->bulletL->addNewBullet(monster7);//如果不行就换成坐标
	monster7->bulletL->moveBullet3(monster7, knight);
	monster7->bulletD->addNewBullet(monster7);//如果不行就换成坐标
	monster7->bulletD->moveBullet4(monster7, knight);

	monster18->bulletR->addNewBullet(monster18);//如果不行就换成坐标
	monster18->bulletR->moveBullet1(monster18, knight);
	monster18->bulletU->addNewBullet(monster18);//如果不行就换成坐标
	monster18->bulletU->moveBullet2(monster18, knight);
	monster18->bulletL->addNewBullet(monster18);//如果不行就换成坐标
	monster18->bulletL->moveBullet3(monster18, knight);
	monster18->bulletD->addNewBullet(monster18);//如果不行就换成坐标
	monster18->bulletD->moveBullet4(monster18, knight);
}

void playLayer::EnemymakeAttackation2(float delta)
{


	monster9->bullet->addNewBullet(monster9);//如果不行就换成坐标
	monster9->bullet->moveBullet(monster9, knight);

	monster12->bullet->addNewBullet(monster12);//如果不行就换成坐标
	monster12->bullet->moveBullet(monster12, knight);

	monster10->bulletR->addNewBullet(monster10);//如果不行就换成坐标
	monster10->bulletR->moveBullet1(monster10, knight);
	monster10->bulletU->addNewBullet(monster10);//如果不行就换成坐标
	monster10->bulletU->moveBullet2(monster10, knight);
	monster10->bulletL->addNewBullet(monster10);//如果不行就换成坐标
	monster10->bulletL->moveBullet3(monster10, knight);
	monster10->bulletD->addNewBullet(monster10);//如果不行就换成坐标
	monster10->bulletD->moveBullet4(monster10, knight);

	monster13->bulletR->addNewBullet(monster13);//如果不行就换成坐标
	monster13->bulletR->moveBullet1(monster13, knight);
	monster13->bulletU->addNewBullet(monster13);//如果不行就换成坐标
	monster13->bulletU->moveBullet2(monster13, knight);
	monster13->bulletL->addNewBullet(monster13);//如果不行就换成坐标
	monster13->bulletL->moveBullet3(monster13, knight);
	monster13->bulletD->addNewBullet(monster13);//如果不行就换成坐标
	monster13->bulletD->moveBullet4(monster13, knight);


	monster14->bulletR->addNewBullet(monster14);//如果不行就换成坐标
	monster14->bulletR->moveBullet1(monster14, knight);
	monster14->bulletU->addNewBullet(monster14);//如果不行就换成坐标
	monster14->bulletU->moveBullet2(monster14, knight);
	monster14->bulletL->addNewBullet(monster14);//如果不行就换成坐标
	monster14->bulletL->moveBullet3(monster14, knight);
	monster14->bulletD->addNewBullet(monster14);//如果不行就换成坐标
	monster14->bulletD->moveBullet4(monster14, knight);

	monster15->bulletR->addNewBullet(monster15);//如果不行就换成坐标
	monster15->bulletR->moveBullet1(monster15, knight);
	monster15->bulletU->addNewBullet(monster15);//如果不行就换成坐标
	monster15->bulletU->moveBullet2(monster15, knight);
	monster15->bulletL->addNewBullet(monster15);//如果不行就换成坐标
	monster15->bulletL->moveBullet3(monster15, knight);
	monster15->bulletD->addNewBullet(monster15);//如果不行就换成坐标
	monster15->bulletD->moveBullet4(monster15, knight);

	monster16->bulletR->addNewBullet(monster16);//如果不行就换成坐标
	monster16->bulletR->moveBullet1(monster16, knight);
	monster16->bulletU->addNewBullet(monster16);//如果不行就换成坐标
	monster16->bulletU->moveBullet2(monster16, knight);
	monster16->bulletL->addNewBullet(monster16);//如果不行就换成坐标
	monster16->bulletL->moveBullet3(monster16, knight);
	monster16->bulletD->addNewBullet(monster16);//如果不行就换成坐标
	monster16->bulletD->moveBullet4(monster16, knight);
}
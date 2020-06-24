

#include "backpack.h"
#include"cocos2d.h"
#include"MyScene.h"
#include"enemy.h"
#include<sstream>
#include"Player.h"
using namespace std;
USING_NS_CC;
int backpack::number_red = 0;
int backpack::number_blue = 0;
Player* backpack::knight = NULL;


Scene* backpack::createScene()
{
	auto scene = Scene::create();
	auto layer = backpack::create();
	scene->addChild(layer);
	return scene;
}
bool backpack::init()
{
	auto size = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//获取窗口大小
	auto* map = TMXTiledMap::create("backpack.tmx");
	addChild(map);
	//添加地图
	auto* label = LabelTTF::create("Backpack", "Arial", 48);
	label->setAnchorPoint(Vec2::ZERO);
	label->setPosition(size.width / 3 + 48, size.height - 48);
	addChild(label, 1, "namelabel");
	//添加背包名称
	auto* pback = MenuItemImage::create("back.jpg", "back.jpg", this, menu_selector(enemy::back));
	auto* back = Menu::create(pback, NULL, NULL);
	back->setAnchorPoint(Vec2::ZERO);
	back->setScale(0.4f);
	back->setPosition(750, 550);
	addChild(back, 1, "backbutton");
	auto* hero = Sprite::create("knight.png");
	hero->setAnchorPoint(Vec2::ZERO);
	hero->setPosition(size.width * 1 / 3 + 304, size.height / 2 + 64);
	hero->setScale(2.0);
	addChild(hero, 1, "hero");//hero添加
	auto* star = Sprite::create("star5.png");
	star->setScale(0.4);
	star->setAnchorPoint(Vec2::ZERO);
	star->setPosition(size.width * 1 / 3 + 240, size.height / 2 + 28);
	addChild(star, 1, "star");//添加星级
	


	stringstream sstr;
	sstr << this->number_red;
	string str = sstr.str();
	auto* labofredbottle = LabelTTF::create(str, "Arial", 32);
	labofredbottle->setAnchorPoint(Vec2::ZERO);
	labofredbottle->setPosition(208, 372);
	addChild(labofredbottle, 2, "rednum");

	auto* redbottle = MenuItemImage::create("red.png", "red.png", this, menu_selector(backpack::useredbottle));
	auto* button2 = Menu::create(redbottle, NULL, NULL);
	button2->setAnchorPoint(Vec2::ZERO);
	button2->setPosition(186, 428);
	button2->setScaleX(3.0);
	button2->setScaleY(2.4);
	addChild(button2, 1, "button2");

	stringstream sstr2;
	sstr2 << this->number_blue;
	string str2 = sstr2.str();
	auto* labofbottle = LabelTTF::create(str2, "Arial", 32);
	labofbottle->setAnchorPoint(Vec2::ZERO);
	labofbottle->setPosition(112, 372);
	addChild(labofbottle, 2, "bluenum");
	auto* bluebottle = MenuItemImage::create("blue.png", "blue.png", this, menu_selector(backpack::usebluebottle));
	auto* button = Menu::create(bluebottle, NULL, NULL);
	button->setAnchorPoint(Vec2::ZERO);
	button->setPosition(80, 428);
	button->setScaleX(3.0);
	button->setScaleY(2.4);
	addChild(button, 1, "button");
	return true;
}
void backpack::usebluebottle(Ref* pSender)
{
	if (this->number_blue != 0 && knight->exp->getCurrentProgress() < knight->exp->getTotalProgress())
	{
		float curMP = knight->exp->getCurrentProgress();
		knight->exp->setCurrentExp(25 + curMP);
		knight->exp->setCurrentProgress(knight->exp->getCurrentProgress() + 2.5);
		this->number_blue--;
	}
	
	stringstream sstr;
	sstr << this->number_blue;
	string str = sstr.str();
	Label* label = (Label*)getChildByName("bluenum");
	label->setString(str);//字符串转为数字以及相反方向转换实例
	if (this->number_blue == 0)
	{
		this->removeChildByName("bluenum");
		this->removeChildByName("button");
	}
}

void backpack::useredbottle(Ref* pSender)
{
	if (this->number_red != 0 && knight->bloodView->getCurrentProgress() < knight->bloodView->getTotalProgress())
	{
		float curHP = knight->getCurrentBlood();
		knight->setCurrentBlood(25 + curHP);
		knight->bloodView->setCurrentProgress(knight->bloodView->getCurrentProgress() + 25);
		this->number_red--;


		stringstream sstr;
		sstr << this->number_red;
		string str = sstr.str();
		Label* label = (Label*)getChildByName("rednum");
		label->setString(str);

		if (this->number_red == 0)
		{
			this->removeChildByName("rednum");
			this->removeChildByName("button2");
		}
	}
}

void backpack::add(int rednumber, int bluenumber, Player* role)
{
	this->knight = role;
	this->number_red = this->number_red + rednumber;
	this->number_blue = this->number_blue + bluenumber;
}

void backpack::setHero(Player*role)
{
	this->knight = role;
}
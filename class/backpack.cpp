#include "backpack.h"
#include"cocos2d.h"
#include"MyScene.h"
#include"enemy.h"
#include<sstream>
using namespace std;
USING_NS_CC;

class hero 
{
public:
	void addblood()
	{
		this->blood += 2;
		if (blood > 6)
		{
			blood = 6;
		}
	}
	void adddefence()
	{
		this->defence += 2;
		if (defence > 10)
		{
			defence = 10;
		}
	}
	hero(int blood, int defence,int speed)
	{
		this->blood = blood;
		this->defence = defence;
		this->speed = speed;
	}
	int return_blood()
	{
		return this->blood;
	}
	int return_defence()
	{
		return this->defence;
	}
	int number_red = 0;
	int number_blue = 0;
private:
	int blood = 6;
	int defence = 10;
	int speed = 3;
	
};
hero character(2,6,3);


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
	label->setPosition(size.width / 3+48, size.height - 48);
	addChild(label, 1, "namelabel");
	//添加背包名称
	auto* pback = MenuItemImage::create("back.jpg", "back.jpg", this, menu_selector(enemy::back));
	auto* back = Menu::create(pback, NULL, NULL);
	back->setAnchorPoint(Vec2::ZERO);
	back->setScale(0.4f);
	back->setPosition(750, 550);
	addChild(back, 1,"backbutton");
	auto* hero = Sprite::create("knight.png");
	hero->setAnchorPoint(Vec2::ZERO);
	hero->setPosition(size.width * 1 / 3+304, size.height / 2+64);
	hero->setScale(2.0);
	addChild(hero, 1, "hero");//hero添加
	auto* star = Sprite::create("star5.png");
	star->setScale(0.4);
	star->setAnchorPoint(Vec2::ZERO);
	star->setPosition(size.width *1/3+240, size.height/2 +28);
	addChild(star, 1, "star");//添加星级
	auto* attribute = Sprite::create("attribute.png");
	attribute->setScale(0.5);
	attribute->setAnchorPoint(Vec2::ZERO);
	attribute->setPosition(504, 80);
	addChild(attribute, 1, "attribute");//添加属性图
	auto* blood = Sprite::create("blood2.png");
	blood->setPosition(634, 246);
	blood->setScaleX(0.5);
	blood->setScaleY(0.5);
	addChild(blood, 1, "blood");
	auto* defence = Sprite::create("defence6.png");
	defence->setPosition(650, 204);
	defence->setScaleX(0.5);
	defence->setScaleY(0.5);
	addChild(defence, 1, "defence");

	
	stringstream sstr;
	sstr <<character.number_red;
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
	sstr2 << character.number_blue;
	string str2 = sstr.str();
	auto* labofbottle = LabelTTF::create(str2, "Arial", 32);
	labofbottle->setAnchorPoint(Vec2::ZERO);
	labofbottle->setPosition(112, 372);
	addChild(labofbottle, 2, "bluenum");
	auto* bluebottle = MenuItemImage::create("blue.png", "blue.png",this, menu_selector(backpack::usebluebottle));
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
	if (character.number_blue != 0&&character.return_defence()<10)
	{
		character.adddefence();
		character.number_blue--;	
	}
	if (character.return_defence() == 1)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence1.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 2)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence2.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 3)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence3.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 4)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence4.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 5)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence5.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 6)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence6.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 7)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence7.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 8)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence8.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 9)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence9.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	if (character.return_defence() == 10)
	{
		this->removeChildByName("defence2");
		auto* defence2 = Sprite::create("defence10.png");
		defence2->setPosition(650, 204);
		defence2->setScaleX(0.5);
		defence2->setScaleY(0.5);
		addChild(defence2, 1, "defence2");
	}
	stringstream sstr;
	sstr << character.number_blue;
	string str = sstr.str();
	Label* label =(Label*)getChildByName("bluenum");
	label->setString(str);//字符串转为数字以及相反方向转换实例
	if (character.number_blue == 0)
	{
		this->removeChildByName("bluenum");
		this->removeChildByName("button");
	}
}
void backpack::useredbottle(Ref* pSender)
{
	if (character.number_red != 0&&character.return_blood ()<6)
	{
		character.addblood();
		character.number_red--;
		
		if (character.return_blood() == 2)
		{
			this->removeChildByName("blood1");
			auto* blood1 = Sprite::create("blood2.png");
			blood1->setPosition(634, 246);
			blood1->setScaleX(0.5);
			blood1->setScaleY(0.5);
			addChild(blood1, 1, "blood1");
		}
		if (character.return_blood() == 3)
		{
			this->removeChildByName("blood1");
			auto* blood1 = Sprite::create("blood3.png");
			blood1->setPosition(634, 246);
			blood1->setScaleX(0.5);
			blood1->setScaleY(0.5);
			addChild(blood1, 1, "blood1");
		}
		if (character.return_blood() == 4)
		{
			this->removeChildByName("blood1");
			auto* blood1 = Sprite::create("blood4.png");
			blood1->setPosition(634, 246);
			blood1->setScaleX(0.5);
			blood1->setScaleY(0.5);
			addChild(blood1, 1, "blood1");
		}
		if (character.return_blood() == 5)
		{
			this->removeChildByName("blood1");
			auto* blood1 = Sprite::create("blood5.png");
			blood1->setPosition(634, 246);
			blood1->setScaleX(0.5);
			blood1->setScaleY(0.5);
			addChild(blood1, 1, "blood1");
		}
		if (character.return_blood() == 6)
		{
			this->removeChildByName("blood1");
			auto* blood1 = Sprite::create("blood6.png");
			blood1->setPosition(634, 246);
			blood1->setScaleX(0.5);
			blood1->setScaleY(0.5);
			addChild(blood1, 1, "blood1");
		}
	}
	stringstream sstr;
	sstr << character.number_red;
	string str = sstr.str();
	Label* label = (Label*)getChildByName("rednum");
	label->setString(str);
	
	if (character.number_red == 0)
	{
		this->removeChildByName("rednum");
		this->removeChildByName("button2");
	}
}
void backpack::add(int rednumber, int bluenumber)
{
	character.number_red =character.number_red+rednumber;
	character.number_blue =character.number_blue+ bluenumber;
	//if (character.number_blue != 0 &&character.number_red != 0)
	//{
		
		//stringstream sstr_red;
		//sstr_red << number_red;
		//string str_red = sstr_red.str();
		//Label* label_red = (Label*)getChildByName("rednum");
		//label_red->setString(str_red);

		//stringstream sstr_blue;
		//sstr_blue << number_blue;
		//string str_blue = sstr_blue.str();
		//Label* label_blue = (Label*)getChildByName("bluenum");
		//label_blue->setString(str_blue);
	//}
	//if (character.number_red == 0)
	//{
		//character.number_red = rednumber;
		//character.number_blue = bluenumber;
		//auto* labofredbottle = LabelTTF::create("0", "Arial", 32);
		//labofredbottle->setAnchorPoint(Vec2::ZERO);
		//labofredbottle->setPosition(208, 372);
		//addChild(labofredbottle, 2, "rednum");
		//auto* redbottle = MenuItemImage::create("red.png", "red.png", this, menu_selector(backpack::useredbottle));
		//auto* button2 = Menu::create(redbottle, NULL, NULL);
		//button2->setAnchorPoint(Vec2::ZERO);
		//button2->setPosition(186, 428);
		//button2->setScaleX(3.0);
		//button2->setScaleY(2.4);
		//addChild(button2, 1, "button2");
		//stringstream sstr_red;
		//sstr_red << number_red;
		//string str_red = sstr_red.str();
		//Label* label_red = (Label*)getChildByName("rednum");
		//label_red->setString(str_red);
	//}
	///if (character.number_blue==0)
	//{
		//character.number_red = rednumber;
		//character.number_blue = bluenumber;
		//auto* labofbottle = LabelTTF::create("3", "Arial", 32);
		//labofbottle->setAnchorPoint(Vec2::ZERO);
		//labofbottle->setPosition(112, 372);
		//addChild(labofbottle, 2, "bluenum");
		//auto* bluebottle = MenuItemImage::create("blue.png", "blue.png", this, menu_selector(backpack::usebluebottle));
		//auto* button = Menu::create(bluebottle, NULL, NULL);
		//button->setAnchorPoint(Vec2::ZERO);
		//button->setPosition(80, 428);
		//button->setScaleX(3.0);
		//button->setScaleY(2.4);
		//addChild(button, 1, "button");
		////stringstream sstr_blue;
		//sstr_blue << number_blue;
		//string str_blue = sstr_blue.str();
		//Label* label_blue = (Label*)getChildByName("bluenum");
		//label_blue->setString(str_blue);
	//}
}
#include "enemy.h"
#include"safemap.h"
#include"cocos2d.h"
USING_NS_CC;
int gold = 2000;
Scene* enemy::createScene()
{
	auto scene = Scene::create();
	auto layer = enemy::create();
	scene->addChild(layer);
	return scene;
}
bool enemy::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto* gold = Sprite::create("goldcoin.jpg");
	gold->setAnchorPoint(Vec2::ZERO);
	gold->setPosition(608, 416);
	gold->setScale(0.3);
	addChild(gold, 1);
	auto* goldcoinlabel = LabelTTF::create("0", "Arial", 30);
	goldcoinlabel->retain();
	goldcoinlabel->setPosition(672, 416);
	this->addChild(goldcoinlabel, 1,"goldcoinlabel");
	
	goldcoinlabel->setString(StringUtils::format("%d",gold));
	goldcoinlabel->setVisible(true);


	auto* pButton1 = MenuItemImage::create("unlock.jpg", "unlock.jpg", this, menu_selector(enemy::unlock));
	auto* button1 = Menu::create(pButton1, NULL, NULL);
	button1->setAnchorPoint(Vec2(0, 0));
	button1->setPosition(352,48 );
	button1->setScale(0.5f);
	addChild(button1);

	auto* attribute = Sprite::create("attribute.png");
	attribute->setAnchorPoint(Vec2::ZERO);
	attribute->setPosition(visibleSize.width*2/3,visibleSize.height/4);
	attribute->setScale(0.5);
	addChild(attribute,1);

	auto* map = TMXTiledMap::create("shumap.tmx");
	addChild(map);
	//auto* BG = Sprite::create("background.jpg");
	//BG->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//this->addChild(BG);
	auto* phero = MenuItemImage::create("knight.png", "knight.png", this, menu_selector(enemy::hero));
	auto* hero = Menu::create(phero, NULL, NULL);
	hero->setPosition(Vec2(64, 544));
	//hero->setScale(2.0);
	this->addChild(hero, 1);

	auto* penemy1 = MenuItemImage::create("enemy1.png", "enemy1.png", this, menu_selector(enemy::enemy1));
	auto* enemy1 = Menu::create(penemy1, NULL, NULL);
	enemy1->setPosition(64, 448);
	//enemy1->setScale(2.0);
	this->addChild(enemy1, 1);

	auto* penemy2 = MenuItemImage::create("enemy2.png", "enemy2.png", this, menu_selector(enemy::enemy2));
	auto* enemy2 = Menu::create(penemy2, NULL, NULL);
	enemy2->setPosition(64, 352);
	//enemy2->setScale(2.0);
	this->addChild(enemy2, 1);

	auto* penemy3 = MenuItemImage::create("enemy3.png", "enemy3.png", this, menu_selector(enemy::enemy3));
	auto* enemy3 = Menu::create(penemy3, NULL, NULL);
	enemy3->setPosition(64, 256);
	//enemy3->setScale(2.0);
	this->addChild(enemy3, 1);

	auto* penemy4 = MenuItemImage::create("enemy4.png", "enemy4.png", this, menu_selector(enemy::enemy4));
	auto* enemy4 = Menu::create(penemy4, NULL, NULL);
	enemy4->setPosition(64, 160);
	this->addChild(enemy4, 1);

	//auto* label = LabelTTF::create("Sorcerer", "Arial", 40);
	//label->setPosition(visibleSize.width / 2, 512);
	//addChild(label, 1);
 //创建标签

	auto* pback = MenuItemImage::create("back.jpg", "back.jpg", this, menu_selector(enemy::back));
	auto* back = Menu::create(pback, NULL, NULL);
	back->setAnchorPoint(Vec2::ZERO);
	back->setScale(0.4f);
	back->setPosition(750, 550);
	addChild(back, 1);

	return true;
}

void enemy::enemy1(Ref* pSender)
{
	Node* preNode = this->getChildByTag(1);
	this->removeChildByTag(1);
	Node* preNode2 = this->getChildByTag(2);
	this->removeChildByTag(2);
	Node* preNode3 = this->getChildByTag(3);
	this->removeChildByTag(3);
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto* label = LabelTTF::create("Sorcerer", "Arial", 60);
	label->setPosition(visibleSize.width / 2+64, 480);
	this->addChild(label,1,1);
	

	auto* enemyImage = Sprite::create("enemy1.png");
	enemyImage->setPosition(visibleSize.width / 3,288);
	this->addChild(enemyImage, 1, 2);
	enemyImage->setScale(2.0);
	auto* star = Sprite::create("star1.png");
	star->setScale(0.4);
	star->setPosition(visibleSize.width / 3, 192);
	this->addChild(star, 1, 3);

}
void enemy::enemy2(Ref* pSender)
{
	Node* preNode = this->getChildByTag(1);
	this->removeChildByTag(1);
	Node* preNode2 = this->getChildByTag(2);
	this->removeChildByTag(2);
	Node* preNode3 = this->getChildByTag(3);
	this->removeChildByTag(3);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto* label = LabelTTF::create("Shooter", "Arial", 60);
	label->setPosition(visibleSize.width / 2+64, 480);
	addChild(label, 1,1);
	auto* enemyImage = Sprite::create("enemy2.png");
	enemyImage->setPosition(visibleSize.width / 3, 288);
	enemyImage->setScale(2.0);
	this->addChild(enemyImage, 1, 2);
	auto* star = Sprite::create("star2.png");
	star->setScale(0.4);
	star->setPosition(visibleSize.width / 3, 192);
	this->addChild(star, 1, 3);

}
void enemy::enemy3(Ref* pSender)
{
	Node* preNode = this->getChildByTag(1);
	this->removeChildByTag(1);
	Node* preNode2 = this->getChildByTag(2);
	this->removeChildByTag(2);
	Node* preNode3 = this->getChildByTag(3);
	this->removeChildByTag(3);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto* label = LabelTTF::create("ShooterFire", "Arial", 60);
	label->setPosition(visibleSize.width / 2+64, 480);
	addChild(label, 1,1);
	auto* enemyImage = Sprite::create("enemy3.png");
	enemyImage->setPosition(visibleSize.width / 3, 288);
	enemyImage->setScale(2.0);
	this->addChild(enemyImage, 1, 2);
	auto* star = Sprite::create("star3.png");
	star->setScale(0.4);
	star->setPosition(visibleSize.width / 3, 192);
	this->addChild(star, 1, 3);

}
void enemy::enemy4(Ref* pSender)
{
	Node* preNode = this->getChildByTag(1);
	this->removeChildByTag(1);
	Node* preNode2 = this->getChildByTag(2);
	this->removeChildByTag(2);
	Node* preNode3 = this->getChildByTag(3);
	this->removeChildByTag(3);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto* label = LabelTTF::create("Wild Boar", "Arial",60);
	label->setPosition(visibleSize.width / 2+64, 480);
	addChild(label, 1,1);
	auto* enemyImage = Sprite::create("enemy4.png");
	enemyImage->setPosition(visibleSize.width / 3, 288);
	enemyImage->setScale(2.0);
	this->addChild(enemyImage, 1, 2);
	auto* star = Sprite::create("star4.png");
	star->setScale(0.4);
	star->setPosition(visibleSize.width / 3, 192);
	this->addChild(star, 1, 3);

}
void enemy::hero(Ref* pSender)
{
	Node* preNode = this->getChildByTag(1);
	this->removeChildByTag(1);//动态监测
	Node* preNode2 = this->getChildByTag(2);
	this->removeChildByTag(2);
	Node* preNode3 = this->getChildByTag(3);
	this->removeChildByTag(3);
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto* label = LabelTTF::create("Hero", "Arial", 60);
	label->setPosition(visibleSize.width / 2+64, 480);
	addChild(label, 1,1);
	auto* enemyImage = Sprite::create("knight.png");
	enemyImage->setPosition(visibleSize.width / 3, 288);
	enemyImage->setScale(2.0);
	this->addChild(enemyImage, 1, 2);
	auto* star = Sprite::create("star5.png");
	star->setScale(0.4);
	star->setPosition(visibleSize.width / 3, 192);
	this->addChild(star, 1, 3);
	
}
void enemy::unlock(Ref* pSender)
{
	gold -= 1000;
	if (gold < 0)
	{
		gold += 1000;
	}
}
void enemy::back(Ref* pSender)
{
	Director::sharedDirector()->popScene();
}
#include "Player.h"
#include"safemap.h"
#include"Exp.h"
#include"PlayLayer.h"

USING_NS_CC;
class playLayer;

Player::Player(void) 
{
}

Player::~Player(void) 
{
}
Player* Player::createWithFileName(const char* name)//ÖØÔØcreate
{
	Player * pobPlayer = new Player();
	if (pobPlayer && pobPlayer->initWithFile(name))
	{
		pobPlayer->autorelease();
		return pobPlayer;
	}
	CC_SAFE_DELETE(pobPlayer);
	return NULL;

}


void Player::InitPlayerSprite(char* xueback, char* xuefore) 
{

	bloodView = new ProgressViewBlood();
	bloodView->setPosition(this->getPosition().x-50,this->getPosition().y+80);
	bloodView->setScale(5.0f);
	bloodView->setBackgroundTexture("bloodOutside.jpg");
	bloodView->setForegroundTexture("blood.jpg");
	bloodView->setTotalProgress(100.0f);
	bloodView->setCurrentProgress(100.0f);
	this->addChild(bloodView, 2);

	exp = new Exp();
	exp->setScale(3.0f);
	exp->setPosition(this->getPosition().x - 50, this->getPosition().y + 100);
	exp->setBackgroundTexture("bloodOutside.jpg");
	exp->setForegroundTexture("exp.jpg");
	exp->setTotalProgress(100.0f);
	exp->setCurrentProgress(100.0f);
	this->addChild(exp, 2);


	myWeapon = weapon::createWithFileName("gun.png");
	myWeapon->setAttack(10);
	myWeapon->setWeaponType(1);
	myWeapon->setPosition(this->getPosition().x+50, this->getPosition().y+20);
	myWeapon->setScale(0.8f);
	myWeapon->setExpData(0);
	this->addChild(myWeapon, -1);
}

void Player::setCurrentBlood(int blood) {
	currentBlood = blood;
}

void Player::attacked(int attack) {
	currentBlood = currentBlood - (attack/5);
	bloodView->setCurrentProgress(bloodView->getCurrentProgress() - (attack/5));
}

void Player::died() 
{
	this->stopAllActions();
	this->setWalkSpeed(0);
	
	this->backToSafeMap();
}

void Player::setWeapon(weapon*newWeapon)
{
	auto currentWeapon = this->myWeapon;
	auto nowWeapon = newWeapon;

	nowWeapon->setPosition(currentWeapon->getPosition());

	currentWeapon->retain();
	nowWeapon->retain();

	currentWeapon->removeFromParent();
	nowWeapon->removeFromParent();

	this->myWeapon = newWeapon;
	myWeapon->setScale(0.8f);
	this->addChild(myWeapon,-1);
}

weapon*& Player::getWeapon()
{
	return this->myWeapon;
}

void Player::init(Point point)
{
	this->setPosition(point);
	this->setTag(0);
	this->scheduleUpdate();
}



void Player::walkWithDirection(Point direction)
{

	_velocity = ccp(direction.x * _walkSpeed, direction.y * _walkSpeed);
	if (_velocity.x >= 0)
	{
		this->setScaleX(1.0);
	}
	else
	{
		this->setScaleX(-1.0);
	}
}

void Player::update(float delta)
{
	_desiredPosition = ccpAdd(this->getPosition(), ccpMult(_velocity, delta));

	if (this->getCurrentBlood() <= 0)
	{
		this->died();
	}
}

void Player::backToSafeMap()
{
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5f, safemap::createScene()));
}
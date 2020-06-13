#include "Player.h"

USING_NS_CC;

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
	bloodView->setPosition(this->getPosition().x,this->getPosition().y+80);
	bloodView->setScale(2.2f);
	bloodView->setBackgroundTexture("bloodOutside.png");
	bloodView->setForegroundTexture("blood.png");
	bloodView->setTotalProgress(100.0f);
	bloodView->setCurrentProgress(100.0f);
	this->addChild(bloodView, 2);

}

void Player::setCurrentBlood(int blood) {
	currentBlood = blood;
	bloodView->setCurrentProgress(blood);
}
int Player::getCurrentBlood() {
	return currentBlood;
}
void Player::attacked(int attack) {
	currentBlood = currentBlood - attack;
	bloodView->setCurrentProgress(bloodView->getCurrentProgress() - attack);
}

//void Player::died() 
//{
//	this->stopAllActions();
//	this->runAction(ËÀÍö¶¯»­);
//}
void Player::init(Point point)
{
	this->setPosition(point);
	this->setTag(0);
	this->scheduleUpdate();
}

//void Player::update(float delta) 
//{
//	if (this->getCurrentBlood() == 0) 
//	{
//		this->died();
//	}
//}

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
}

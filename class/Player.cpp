#include "Player.h"

USING_NS_CC;

Player::Player(void) {
}

Player::~Player(void) {
}
Player* Player::createWithFileName(char* name)//ÖØÔØcreate
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


CCSprite* Player::GetSprite() {
	return m_MonsterSprite;
}

void Player::InitPlayerSprite() {

	bloodView = new ProgressViewBlood();
	//bloodView->setPosition(ccp(150, 750));
	bloodView->setScale(2.2f);
	bloodView->setBackgroundTexture("bloodOutside.jpg");
	bloodView->setForegroundTexture("blood.jpg");
	bloodView->setTotalProgress(100.0f);
	bloodView->setCurrentProgress(100.0f);
	this->addChild(bloodView, 2);

	exp = new Exp();
	exp->setScale(2.2f);
	exp->setBackgroundTexture("bloodOutside.jpg");
	exp->setForegroundTexture("exp.jpg");
	exp->setTotalProgress(100.0f);
	exp->setCurrentProgress(100.0f);
	this->addChild(bloodView, 2);
}

void Player::setCurrentBlood(int blood) {
	currentBlood = blood;
}
int Player::getCurrentBlood() {
	return currentBlood;
}
void Player::attacked(int attack) {
	currentBlood = currentBlood - attack;
	bloodView->setCurrentProgress(bloodView->getCurrentProgress() - attack);
}

void Player::died() {
	this->stopAllActions();
	//this->runAction(ËÀÍö¶¯»­);
}
void Player::init(Point point){
	this->setPosition(point);
	this->setTag(0);
	this->scheduleUpdate();
}
void Player::update(float delta) {
	if (this->getCurrentBlood() == 0) {
		this->died();
	}
}
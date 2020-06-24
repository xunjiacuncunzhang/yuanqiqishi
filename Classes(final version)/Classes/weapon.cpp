#include "weapon.h"
#include"Bullet.h"
#include"Player.h"
#include"Monsterwitcher.h"
USING_NS_CC;

weapon::weapon(void) {
}

weapon::~weapon(void) {
}

weapon* weapon::createWithFileName(char* name)//重载create
{
	weapon* pweapon = new weapon();
	if (pweapon && pweapon->initWithFile(name))
	{
		pweapon->autorelease();
		return pweapon;
	}
	CC_SAFE_DELETE(pweapon);
	return NULL;

}

void weapon::InitweaponSprite() {
	bullet = Bullet::createbullet();
	addChild(bullet);
}

void weapon::setAttack(INT32 newAttack)
{
	this->attack = newAttack;
}

INT32 weapon::getAttack()
{
	return this->attack;
}

void weapon::setWeaponType(INT32 _type)
{
	this->type = _type;
}

INT32 weapon::getWeaponType()
{
	return this->type;
}

void weapon::isCollision(Player* player, Entity *monster) {//这里用到许同学的怪物类

	player->exp->setCurrentExp(-(this->getExpData()));
	player->exp->setCurrentProgress(player->exp->getCurrentProgress() - (this->getExpData() / 100));

	auto posMonster = monster->getPosition();//获取怪物位置
	auto posPlayer = player->getPosition();
	auto w1 = player->getContentSize().width;
	auto w2 = monster->getContentSize().width;

	auto h1 = player->getContentSize().height;
	auto h2 = monster->getContentSize().height;
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	CCLOG("monsterPos:%d %d", posMonster.x, posMonster.y);

	if (abs(posMonster.x - posPlayer.x) < w1 + w2 && abs(posMonster.y - posPlayer.y) < h1 + h2)
	{
		monster->attacked(this->attack);
	}

	//if (monster->getCurrentBlood() == 0) {
	//        monster->died();//如果怪物死亡
	//}
}

void weapon::RotateWhileWalk(Point direction)
{
	//行走方向向量
	Point shootVector = direction;
	//向量标准化(即向量长度为1)
	Point normalizedVector = ccpNormalize(shootVector);
	//算出旋转的弧度
	float radians = atan2(normalizedVector.y, -normalizedVector.x);
	//将弧度转换成角度
	float degree = CC_RADIANS_TO_DEGREES(radians);


	//匀速旋转需要我们设置一下速度，这里假设旋转速度为 2π (rad/s)
	float rotateSpeed = 2 * M_PI;
	//那么旋转1弧度所用时间为
	float rotate_1rad_time = 1 / rotateSpeed;
	//所以旋转的时长为
	float rotateDuration = fabs(radians * rotate_1rad_time);
}


void weapon::makeRotate(Player* knight, Entity* monster)
{
	//射击方向向量
	Point shootVector =  knight->getPosition()- monster->getPosition();
	//向量标准化(即向量长度为1)
	Point normalizedVector = ccpNormalize(shootVector);
	//算出旋转的弧度
	float radians = atan2(normalizedVector.y, -normalizedVector.x);
	//将弧度转换成角度
	float degree = CC_RADIANS_TO_DEGREES(radians);


	//匀速旋转需要我们设置一下速度，这里假设旋转速度为 2π (rad/s)
	float rotateSpeed = 2 * M_PI;
	//那么旋转1弧度所用时间为
	float rotate_1rad_time = 1 / rotateSpeed;
	//所以旋转的时长为
	float rotateDuration = fabs(radians * rotate_1rad_time);


	//最后执行旋转
	this->runAction(RotateTo::create(rotateDuration, degree));

	/*this->controlBullet(knight, monster, this->getAttack());*/
}

void weapon::rotateBack()
{
	CCActionInterval * actionTo0 = CCRotateTo::create(2, 0);
	this->runAction(CCSequence::create(actionTo0, NULL));
}

void weapon::setExpData(float data)
{
	this->expData = data;
}

float weapon::getExpData()
{
	return this->expData;
}
#include "weapon.h"
#include"Bullet.h"
#include"Player.h"
#include"Monsterwitcher.h"
USING_NS_CC;

weapon::weapon(void) {
}

weapon::~weapon(void) {
}

weapon* weapon::createWithFileName(char* name)//����create
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

void weapon::isCollision(Player* player, Entity *monster) {//�����õ���ͬѧ�Ĺ�����

	player->exp->setCurrentExp(-(this->getExpData()));
	player->exp->setCurrentProgress(player->exp->getCurrentProgress() - (this->getExpData() / 100));

	auto posMonster = monster->getPosition();//��ȡ����λ��
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
	//        monster->died();//�����������
	//}
}

void weapon::RotateWhileWalk(Point direction)
{
	//���߷�������
	Point shootVector = direction;
	//������׼��(����������Ϊ1)
	Point normalizedVector = ccpNormalize(shootVector);
	//�����ת�Ļ���
	float radians = atan2(normalizedVector.y, -normalizedVector.x);
	//������ת���ɽǶ�
	float degree = CC_RADIANS_TO_DEGREES(radians);


	//������ת��Ҫ��������һ���ٶȣ����������ת�ٶ�Ϊ 2�� (rad/s)
	float rotateSpeed = 2 * M_PI;
	//��ô��ת1��������ʱ��Ϊ
	float rotate_1rad_time = 1 / rotateSpeed;
	//������ת��ʱ��Ϊ
	float rotateDuration = fabs(radians * rotate_1rad_time);
}


void weapon::makeRotate(Player* knight, Entity* monster)
{
	//�����������
	Point shootVector =  knight->getPosition()- monster->getPosition();
	//������׼��(����������Ϊ1)
	Point normalizedVector = ccpNormalize(shootVector);
	//�����ת�Ļ���
	float radians = atan2(normalizedVector.y, -normalizedVector.x);
	//������ת���ɽǶ�
	float degree = CC_RADIANS_TO_DEGREES(radians);


	//������ת��Ҫ��������һ���ٶȣ����������ת�ٶ�Ϊ 2�� (rad/s)
	float rotateSpeed = 2 * M_PI;
	//��ô��ת1��������ʱ��Ϊ
	float rotate_1rad_time = 1 / rotateSpeed;
	//������ת��ʱ��Ϊ
	float rotateDuration = fabs(radians * rotate_1rad_time);


	//���ִ����ת
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
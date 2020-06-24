#include "Enemywitcherbullet.h"
#include"Player.h"

USING_NS_CC;

Enemywitcherbullet::Enemywitcherbullet() {

}

Enemywitcherbullet::~Enemywitcherbullet() {
	m_allBulletArray->release();
}

Enemywitcherbullet* Enemywitcherbullet::createbullet()
{
	Enemywitcherbullet* pbullet = new Enemywitcherbullet();
	if (pbullet && pbullet->init())
	{
		pbullet->autorelease();
		return pbullet;
	}
	CC_SAFE_DELETE(pbullet);
	return NULL;
}

bool Enemywitcherbullet::init()
{
	if (!Enemywitcherbullet::create())
	{
		return false;
	}

	winSize = CCDirector::sharedDirector()->getWinSize();

	//�����������飬�����Ѵ��ڵ��ӵ�
	m_allBulletArray = CCArray::create();
	m_allBulletArray->retain();

	//�ӵ���ͼ
	m_bulletSprite = CCSprite::create("bullet.png");
	//m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
	addChild(m_bulletSprite);
	return true;

}

//����һ�����ӵ�
void Enemywitcherbullet::addNewBullet(Monsterwitcher* monsterwitcher) {//������оͻ�������
	//����һ���ӵ�����ӵ�BatchNode�С�
	Point point = monsterwitcher->getPosition();
	m_bulletSprite->setPosition(point);
}


//�ƶ��ӵ�1 
void Enemywitcherbullet::moveBullet1(Monsterwitcher* monsterwitcher, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcher->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("monsterPos:%d %d", posmonster.x,posmonster.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(posplayer.x + 100, posplayer.y+100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcher->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 10 || bullet->getPosition().y >= posplayer.y + 10)
	{
		player->attacked(5);
	}*/


	if (bullet->getPosition().x <= posplayer.x && bullet->getPosition().y <= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}
	if (player->getCurrentBlood() == 0) {
		player->died();//�����������
	}
}
void Enemywitcherbullet::moveBullet2(Monsterwitcher* monsterwitcher, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcher->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(-posplayer.x-100, -posplayer.y-100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcher->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 10 || bullet->getPosition().y >= posplayer.y + 10)
	{
		player->attacked(5);
	}*/


	/*if (bullet->getPosition().x <= posplayer.x && bullet->getPosition().y <= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}*/
	if (player->getCurrentBlood() == 0) {
		player->died();//�����������
	}
}

void Enemywitcherbullet::moveBullet3(Monsterwitcher* monsterwitcher, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcher->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(posplayer.x, posplayer.y+100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcher->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 10 || bullet->getPosition().y >= posplayer.y + 10)
	{
		player->attacked(5);
	}*/

	/*if (bullet->getPosition().x <= posplayer.x && bullet->getPosition().y <= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}*/

	if (player->getCurrentBlood() == 0) {
		player->died();//�����������
	}
}

void Enemywitcherbullet::moveBullet4(Monsterwitcher* monsterwitcher, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcher->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(-posplayer.x , -posplayer.y-100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcher->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x <= posplayer.x&& bullet->getPosition().y <= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//�����������
	}
}


void Enemywitcherbullet::setAttack(INT32 _attack)
{
	this->bulletAttack = _attack;
}
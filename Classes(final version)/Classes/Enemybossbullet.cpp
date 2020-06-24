#include "Enemybossbullet.h"
#include"Player.h"

USING_NS_CC;

Enemybossbullet::Enemybossbullet() {

}

Enemybossbullet::~Enemybossbullet() {
	m_allBulletArray->release();
}

Enemybossbullet* Enemybossbullet::createbullet()
{
	Enemybossbullet* pbullet = new Enemybossbullet();
	if (pbullet && pbullet->init())
	{
		pbullet->autorelease();
		return pbullet;
	}
	CC_SAFE_DELETE(pbullet);
	return NULL;
}

bool Enemybossbullet::init()
{
	if (!Enemybossbullet::create())
	{
		return false;
	}

	winSize = CCDirector::sharedDirector()->getWinSize();

	//�����������飬�����Ѵ��ڵ��ӵ�
	m_allBulletArray = CCArray::create();
	m_allBulletArray->retain();

	//�ӵ���ͼ
	m_bulletSprite = CCSprite::create("bossbullet.png");
	//m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
	addChild(m_bulletSprite);
	return true;

}

//����һ�����ӵ�
void Enemybossbullet::addNewBullet(Monsterwitcherboss* monsterwitcherboss) {//������оͻ�������
	//����һ���ӵ�����ӵ�BatchNode�С�
	Point point = monsterwitcherboss->getPosition();
	m_bulletSprite->setPosition(point);
}



//�ƶ��ӵ�1 
void Enemybossbullet::moveBullet1(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcherboss->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("monsterPos:%d %d", posmonster.x,posmonster.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(20.0f, Vec2(-posplayer.x - 100, -posplayer.y-100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcherboss->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	if (bullet->getPosition().x >= posplayer.x&& bullet->getPosition().y >= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}


	if (player->getCurrentBlood() == 0) {
	        player->died();//�����������
	}
}

void Enemybossbullet::moveBullet2(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcherboss->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(20.0f, Vec2(posplayer.x + 100, posplayer.y + 100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcherboss->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 20 || bullet->getPosition().y >= posplayer.y + 20)
	{
		player->attacked(5);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//�����������
	}
}

void Enemybossbullet::moveBullet3(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcherboss->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(20.0f, Vec2(posplayer.x, posplayer.y + 100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcherboss->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 20 || bullet->getPosition().y >= posplayer.y + 20)
	{
		player->attacked(5);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//�����������
	}
}

void Enemybossbullet::moveBullet4(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//��������ÿ���ӵ���λ��
			//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//��ȡ���λ��
	auto posmonster = monsterwitcherboss->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(15.0f, Vec2(-posplayer.x, -posplayer.y - 100));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monsterwitcherboss->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 20 || bullet->getPosition().y >= posplayer.y + 20)
	{
		player->attacked(5);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//�����������
	}
}

void Enemybossbullet::setAttack(INT32 _attack)
{
	this->bulletAttack = _attack;
}
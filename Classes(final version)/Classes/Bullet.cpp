#include "Bullet.h"
#include"Player.h"
#include"weapon.h"
USING_NS_CC;

Bullet::Bullet() {

}

Bullet::~Bullet() {
	/* m_allBulletArray->release();*/
}

Bullet* Bullet::createbullet()
{
	Bullet* pbullet = new Bullet();
	if (pbullet && pbullet->init())
	{
		pbullet->autorelease();
		return pbullet;
	}
	CC_SAFE_DELETE(pbullet);
	return NULL;
}

bool Bullet::init()
{
	if (!Bullet::create())
	{
		return false;
	}

	winSize = CCDirector::sharedDirector()->getWinSize();

	//�����������飬�����Ѵ��ڵ��ӵ�
	/*m_allBulletArray = CCArray::create();
	m_allBulletArray->retain();*/

	//�ӵ���ͼ
	m_bulletSprite = CCSprite::create("bullet1.png");
	//m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
	addChild(m_bulletSprite);

	return true;

}

//����һ�����ӵ�
void Bullet::addNewBullet(Player *knight) {//������оͻ�������
	//����һ���ӵ�����ӵ�BatchNode�С�
  /*  CCSprite* newBullet = CCSprite::createWithTexture(m_bulletSprite->getTexture());*/
	Point pointWeapon = knight->getPosition();
	m_bulletSprite->setPosition(pointWeapon);
	/* m_bulletSprite->addChild(newBullet);*/

	 //����ӵ����Ѵ����ӵ�����
   /*  m_allBulletArray->addObject(newBullet);*/
}



//�ƶ��ӵ� 
void Bullet::moveBullet(Player* player, Entity *monster, INT32 attack, Exp* exp, weapon *weapon) {//�����õ���ͬѧ�Ĺ�����
	//��������ÿ���ӵ���λ��
		//��ȡһ���ӵ�����
	exp->setCurrentExp(-(weapon->getExpData()));
	exp->setCurrentProgress(exp->getCurrentProgress() - (weapon->getExpData() / 100));

	CCSprite* bullet = m_bulletSprite;
	auto posMonster = monster->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	CCLOG("monsterPos:%d %d", posMonster.x, posMonster.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	/*bullet->setPosition(posMonster);*/

	//����λ��
	CCActionInterval* moveTo = CCMoveTo::create(0.5f, posMonster);//�����λ��
	bullet->runAction(moveTo);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monster->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	monster->attacked(attack);

	//if (monster->getCurrentBlood() == 0) {
	//        monster->died();//�����������
	//}
}
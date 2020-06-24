#include "Enemyshooterbullet.h"
#include"Player.h"

USING_NS_CC;

Enemyshooterbullet::Enemyshooterbullet() {

}

Enemyshooterbullet::~Enemyshooterbullet() {
    m_allBulletArray->release();
}

Enemyshooterbullet* Enemyshooterbullet::createbullet()
{
	Enemyshooterbullet* pbullet = new Enemyshooterbullet();
	if (pbullet && pbullet->init())
	{
		pbullet->autorelease();
		return pbullet;
	}
	CC_SAFE_DELETE(pbullet);
	return NULL;
}

bool Enemyshooterbullet::init()
{
	if (!Enemyshooterbullet::create())
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
void Enemyshooterbullet::addNewBullet(Monstershooter*monstershooter) {//������оͻ�������
	//����һ���ӵ�����ӵ�BatchNode�С�
    Point point= monstershooter->getPosition();
	m_bulletSprite->setPosition(point);
}



//�ƶ��ӵ� 
void Enemyshooterbullet::moveBullet(Monstershooter* monster, Player* player) {
//��������ÿ���ӵ���λ��
		//��ȡһ���ӵ�����
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = monster->getPosition();//��ȡ����λ��
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);


	//����λ��
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(posplayer.x+100,posplayer.y));//�����λ��
	bullet->runAction(moveBy);
	//����ѵ�����ʧλ�ã����Ƴ����ӵ�
	CCRect cr2 = monster->boundingBox();//��ȡ������ӵ�
	CCRect cr1 = bullet->boundingBox();

	if (bullet->getPosition().x <= posplayer.x&& bullet->getPosition().y <= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}


	//if (monster->getCurrentBlood() == 0) {
	//        monster->died();//�����������
	//}
}

void Enemyshooterbullet::setAttack(INT32 _attack)
{
	this->bulletAttack = _attack;
}
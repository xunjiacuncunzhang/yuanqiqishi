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

	//创建对象数组，保存已存在的子弹
	/*m_allBulletArray = CCArray::create();
	m_allBulletArray->retain();*/

	//子弹贴图
	m_bulletSprite = CCSprite::create("bullet1.png");
	//m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
	addChild(m_bulletSprite);

	return true;

}

//增加一个新子弹
void Bullet::addNewBullet(Player *knight) {//如果不行就换成坐标
	//构建一个子弹，添加到BatchNode中。
  /*  CCSprite* newBullet = CCSprite::createWithTexture(m_bulletSprite->getTexture());*/
	Point pointWeapon = knight->getPosition();
	m_bulletSprite->setPosition(pointWeapon);
	/* m_bulletSprite->addChild(newBullet);*/

	 //添加子弹到已存在子弹数组
   /*  m_allBulletArray->addObject(newBullet);*/
}



//移动子弹 
void Bullet::moveBullet(Player* player, Entity *monster, INT32 attack, Exp* exp, weapon *weapon) {//这里用到许同学的怪物类
	//遍历更新每个子弹的位置
		//获取一个子弹对象
	exp->setCurrentExp(-(weapon->getExpData()));
	exp->setCurrentProgress(exp->getCurrentProgress() - (weapon->getExpData() / 100));

	CCSprite* bullet = m_bulletSprite;
	auto posMonster = monster->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	CCLOG("monsterPos:%d %d", posMonster.x, posMonster.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	/*bullet->setPosition(posMonster);*/

	//更新位置
	CCActionInterval* moveTo = CCMoveTo::create(0.5f, posMonster);//怪物的位置
	bullet->runAction(moveTo);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monster->boundingBox();//获取怪物的子弹
	CCRect cr1 = bullet->boundingBox();

	monster->attacked(attack);

	//if (monster->getCurrentBlood() == 0) {
	//        monster->died();//如果怪物死亡
	//}
}
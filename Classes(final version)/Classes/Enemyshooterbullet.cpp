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

	//创建对象数组，保存已存在的子弹
	m_allBulletArray = CCArray::create();
	m_allBulletArray->retain();

	//子弹贴图
	m_bulletSprite = CCSprite::create("bullet.png");
	//m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
	addChild(m_bulletSprite);
	return true;

}

//增加一个新子弹
void Enemyshooterbullet::addNewBullet(Monstershooter*monstershooter) {//如果不行就换成坐标
	//构建一个子弹，添加到BatchNode中。
    Point point= monstershooter->getPosition();
	m_bulletSprite->setPosition(point);
}



//移动子弹 
void Enemyshooterbullet::moveBullet(Monstershooter* monster, Player* player) {
//遍历更新每个子弹的位置
		//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = monster->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);


	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(posplayer.x+100,posplayer.y));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monster->boundingBox();//获取怪物的子弹
	CCRect cr1 = bullet->boundingBox();

	if (bullet->getPosition().x <= posplayer.x&& bullet->getPosition().y <= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}


	//if (monster->getCurrentBlood() == 0) {
	//        monster->died();//如果怪物死亡
	//}
}

void Enemyshooterbullet::setAttack(INT32 _attack)
{
	this->bulletAttack = _attack;
}
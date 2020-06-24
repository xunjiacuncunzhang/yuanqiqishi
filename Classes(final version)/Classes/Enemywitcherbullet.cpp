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
void Enemywitcherbullet::addNewBullet(Monsterwitcher* monsterwitcher) {//如果不行就换成坐标
	//构建一个子弹，添加到BatchNode中。
	Point point = monsterwitcher->getPosition();
	m_bulletSprite->setPosition(point);
}


//移动子弹1 
void Enemywitcherbullet::moveBullet1(Monsterwitcher* monsterwitcher, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcher->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("monsterPos:%d %d", posmonster.x,posmonster.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(posplayer.x + 100, posplayer.y+100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcher->boundingBox();//获取怪物的子弹
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
		player->died();//如果怪物死亡
	}
}
void Enemywitcherbullet::moveBullet2(Monsterwitcher* monsterwitcher, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcher->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(-posplayer.x-100, -posplayer.y-100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcher->boundingBox();//获取怪物的子弹
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
		player->died();//如果怪物死亡
	}
}

void Enemywitcherbullet::moveBullet3(Monsterwitcher* monsterwitcher, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcher->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(posplayer.x, posplayer.y+100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcher->boundingBox();//获取怪物的子弹
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
		player->died();//如果怪物死亡
	}
}

void Enemywitcherbullet::moveBullet4(Monsterwitcher* monsterwitcher, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcher->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(3.0f, Vec2(-posplayer.x , -posplayer.y-100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcher->boundingBox();//获取怪物的子弹
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x <= posplayer.x&& bullet->getPosition().y <= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//如果怪物死亡
	}
}


void Enemywitcherbullet::setAttack(INT32 _attack)
{
	this->bulletAttack = _attack;
}
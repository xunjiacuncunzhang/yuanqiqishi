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

	//创建对象数组，保存已存在的子弹
	m_allBulletArray = CCArray::create();
	m_allBulletArray->retain();

	//子弹贴图
	m_bulletSprite = CCSprite::create("bossbullet.png");
	//m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
	addChild(m_bulletSprite);
	return true;

}

//增加一个新子弹
void Enemybossbullet::addNewBullet(Monsterwitcherboss* monsterwitcherboss) {//如果不行就换成坐标
	//构建一个子弹，添加到BatchNode中。
	Point point = monsterwitcherboss->getPosition();
	m_bulletSprite->setPosition(point);
}



//移动子弹1 
void Enemybossbullet::moveBullet1(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcherboss->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("monsterPos:%d %d", posmonster.x,posmonster.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(20.0f, Vec2(-posplayer.x - 100, -posplayer.y-100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcherboss->boundingBox();//获取怪物的子弹
	CCRect cr1 = bullet->boundingBox();

	if (bullet->getPosition().x >= posplayer.x&& bullet->getPosition().y >= posplayer.y)
	{
		player->attacked(this->bulletAttack);
	}


	if (player->getCurrentBlood() == 0) {
	        player->died();//如果怪物死亡
	}
}

void Enemybossbullet::moveBullet2(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcherboss->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(20.0f, Vec2(posplayer.x + 100, posplayer.y + 100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcherboss->boundingBox();//获取怪物的子弹
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 20 || bullet->getPosition().y >= posplayer.y + 20)
	{
		player->attacked(5);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//如果怪物死亡
	}
}

void Enemybossbullet::moveBullet3(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcherboss->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(20.0f, Vec2(posplayer.x, posplayer.y + 100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcherboss->boundingBox();//获取怪物的子弹
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 20 || bullet->getPosition().y >= posplayer.y + 20)
	{
		player->attacked(5);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//如果怪物死亡
	}
}

void Enemybossbullet::moveBullet4(Monsterwitcherboss* monsterwitcherboss, Player* player) {
	//遍历更新每个子弹的位置
			//获取一个子弹对象
	CCSprite* bullet = m_bulletSprite;
	auto posplayer = player->getPosition();//获取玩家位置
	auto posmonster = monsterwitcherboss->getPosition();//获取怪物位置
	CCLOG("playerPos:%d %d", player->getPosition().x, player->getPosition().y);
	//CCLOG("playerPos:%d %d", posplayer.x, posplayer.y);
	CCLOG("bulletPos:%d %d", bullet->getPosition().x, bullet->getPosition().y);

	bullet->setPosition(posmonster);

	//更新位置
	CCActionInterval* moveBy = CCMoveBy::create(15.0f, Vec2(-posplayer.x, -posplayer.y - 100));//怪物的位置
	bullet->runAction(moveBy);
	//如果已到达消失位置，就移除该子弹
	CCRect cr2 = monsterwitcherboss->boundingBox();//获取怪物的子弹
	CCRect cr1 = bullet->boundingBox();

	/*if (bullet->getPosition().x >= posplayer.x + 20 || bullet->getPosition().y >= posplayer.y + 20)
	{
		player->attacked(5);
	}*/


	if (player->getCurrentBlood() == 0) {
		player->died();//如果怪物死亡
	}
}

void Enemybossbullet::setAttack(INT32 _attack)
{
	this->bulletAttack = _attack;
}
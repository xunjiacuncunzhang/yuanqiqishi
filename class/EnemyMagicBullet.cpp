
/**
*功能 创建魔法弹并初始化魔法弹的运动轨迹
*/
#include "EnemyMagicBullet.h"
EnemyMagicBullet::EnemyMagicBullet(Node* monsterwitcher) {
	this->monsterwitcher = monsterwitcher;
}
EnemyMagicBullet::~EnemyMagicBullet() {
}
/**
*创建魔法弹的静态方法
*/
EnemyMagicBullet* EnemyMagicBullet::create(Node* monsterwitcher) {
	EnemyMagicBullet* pRet = new EnemyMagicBullet(monsterwitcher);
	if (pRet && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}

}
bool EnemyMagicBullet::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		//创建BatchNode节点
		bulletBatchNode = SpriteBatchNode::create("bullet.png");
		this->addChild(bulletBatchNode);

		//每隔0.2S调用一次发射子弹函数
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet1), 1.2f);
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet2), 1.2f);
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet3), 1.2f);
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet4), 1.2f);
		bRet = true;
	} while (0);
	return bRet;
}
/**
*用缓存的方法创建子弹，并初始化子弹的运动和运动后的事件
*/
void EnemyMagicBullet::ShootBullet1(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//从缓存中创建子弹
		auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
		//将创建好的子弹添加到BatchNode中进行批次渲染
		bulletBatchNode->addChild(spritebullet);
		//将创建好的子弹添加到容器
		vecBullet.pushBack(spritebullet);

		Point bulletPos1 = (Point(Pos.x,
			Pos.y + monsterwitcher->getContentSize().height / 2 + 20));
		spritebullet->setPosition(bulletPos1);
		spritebullet->setScale(0.8f);
	


	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 200;//实际飞行的时间

	
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos1.x, winSize.height));

	//子弹执行完动作后进行函数回调，调用移除子弹函数
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//子弹开始跑动
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}
void EnemyMagicBullet::ShootBullet2(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//从缓存中创建子弹
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//将创建好的子弹添加到BatchNode中进行批次渲染
	bulletBatchNode->addChild(spritebullet);
	//将创建好的子弹添加到容器
	vecBullet.pushBack(spritebullet);

	Point bulletPos1 = (Point(Pos.x ,
		Pos.y+ monsterwitcher->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos1);
	spritebullet->setScale(0.8f);



	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 200;//实际飞行的时间

	
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(winSize.width, bulletPos1.y));

	//子弹执行完动作后进行函数回调，调用移除子弹函数
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//子弹开始跑动
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}
void EnemyMagicBullet::ShootBullet3(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//从缓存中创建子弹
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//将创建好的子弹添加到BatchNode中进行批次渲染
	bulletBatchNode->addChild(spritebullet);
	//将创建好的子弹添加到容器
	vecBullet.pushBack(spritebullet);

	Point bulletPos1 = (Point(Pos.x,
		Pos.y + monsterwitcher->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos1);
	spritebullet->setScale(0.8f);



	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 70;//实际飞行的时间


	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos1.x, -winSize.height));

	//子弹执行完动作后进行函数回调，调用移除子弹函数
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//子弹开始跑动
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}
void EnemyMagicBullet::ShootBullet4(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//从缓存中创建子弹
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//将创建好的子弹添加到BatchNode中进行批次渲染
	bulletBatchNode->addChild(spritebullet);
	//将创建好的子弹添加到容器
	vecBullet.pushBack(spritebullet);

	Point bulletPos1 = (Point(Pos.x,
		Pos.y + monsterwitcher->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos1);
	spritebullet->setScale(0.8f);



	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 70;//实际飞行的时间

	//子弹运行的距离和时间，从飞机处开始运行到屏幕顶端
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(-winSize.width, bulletPos1.y));

	//子弹执行完动作后进行函数回调，调用移除子弹函数
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//子弹开始跑动
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}


/**
 * 移除子弹，将子弹从容器中移除，同时也从SpriteBatchNode中移除
 */
void EnemyMagicBullet::removeBullet(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;
	this->bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
/**
*返回子弹列表，用来与敌机做碰撞检测
*/
Vector <Sprite*>& EnemyMagicBullet::GetBullet() {
	return vecBullet;
}
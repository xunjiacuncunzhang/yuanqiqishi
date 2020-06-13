
/**
*功能 创建子弹并初始化子弹的运动轨迹
*/
#include "EnemyBulletLayer.h"
EnemyBulletLayer::EnemyBulletLayer(Node* monstershooter) {
	this->monstershooter = monstershooter;
}
EnemyBulletLayer::~EnemyBulletLayer() {
}
/**
*创建子弹的静态方法
*/
EnemyBulletLayer* EnemyBulletLayer::create(Node* monstershooter) {
	EnemyBulletLayer* pRet = new EnemyBulletLayer(monstershooter);
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
bool EnemyBulletLayer::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		//创建BatchNode节点
		bulletBatchNode = SpriteBatchNode::create("bullet.png");
		this->addChild(bulletBatchNode);

		//每隔0.2S调用一次发射子弹函数
		this->schedule(schedule_selector(EnemyBulletLayer::ShootBullet), 1.2f);
		bRet = true;
	} while (0);
	return bRet;
}
/**
*用缓存的方法创建子弹，并初始化子弹的运动和运动后的事件
*/
void EnemyBulletLayer::ShootBullet(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monstershooter->getPosition();
	//从缓存中创建子弹
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//将创建好的子弹添加到BatchNode中进行批次渲染
	bulletBatchNode->addChild(spritebullet);
	//将创建好的子弹添加到容器
	vecBullet.pushBack(spritebullet);

	Point bulletPos = (Point(Pos.x,
		Pos.y + monstershooter->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.8f);


	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 300;//实际飞行的时间

	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos.x, winSize.height));

	//子弹执行完动作后进行函数回调，调用移除子弹函数
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyBulletLayer::removeBullet, this));

	//子弹开始跑动
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}

/**
 * 移除子弹，将子弹从容器中移除，同时也从SpriteBatchNode中移除
 */
void EnemyBulletLayer::removeBullet(Node* pNode) {
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
Vector <Sprite*>& EnemyBulletLayer::GetBullet() {
	return vecBullet;
}

/**
*功能 创建魔法弹并初始化魔法弹的运动轨迹
*/
#include "cocos2d.h"
USING_NS_CC;

class EnemyMagicBullet : public cocos2d::Layer
{
public:
	EnemyMagicBullet(CCNode* monsterwitcher);
	~EnemyMagicBullet();
	virtual bool init();

	//创建魔法弹
	static  EnemyMagicBullet* create(CCNode* monsterwitcher);

	//移除超出屏幕可视范围的魔法弹或者碰撞后的魔法弹清除
	void removeBullet(Node* pNode);

	//发射魔法弹，在其中进行魔法弹的渲染和魔法弹的动作，默认为多魔法弹
	void ShootBullet1(float dt);
	void ShootBullet2(float dt);
	void ShootBullet3(float dt);
	void ShootBullet4(float dt);

	
	//返回子弹列表
	Vector <Sprite*>& GetBullet();
public:
	Vector <Sprite*>vecBullet;//魔法弹容器
	SpriteBatchNode* bulletBatchNode;//批次渲染节点
	CCNode* monsterwitcher;
};


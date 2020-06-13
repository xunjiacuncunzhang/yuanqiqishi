
/**
*功能 创建子弹并初始化子弹的运动轨迹
*/
#include "cocos2d.h"
USING_NS_CC;
const float FlYVElOCITY = 500;//运行速度，可以自己控制，每秒所走的像素
class EnemyBulletLayer : public cocos2d::Layer
{
public:
	EnemyBulletLayer(CCNode* monstershooter);
	~EnemyBulletLayer();
	virtual bool init();

	//根据英雄飞机创建子弹
	static EnemyBulletLayer* create(CCNode* monstershooter);

	//移除超出屏幕可视范围的子弹或者碰撞后的子弹清除
	void removeBullet(Node* pNode);

	//发射子弹，在其中进行子弹的渲染和子弹的飞行动作，默认为单子弹
	void ShootBullet(float dt);

	//返回子弹列表
	Vector <Sprite*>& GetBullet();
public:
	Vector <Sprite*>vecBullet;//子弹容器
	SpriteBatchNode* bulletBatchNode;//批次渲染节点
	CCNode*monstershooter ;
};


#ifndef __Enemywitcherbullet_H__
#define __Enemywitcherbullet_H__

#include "cocos2d.h"
#include"Monsterwitcher.h"
#include"Entity.h"

USING_NS_CC;

class Monsterwitcher;
class Player;
class Enemywitcherbullet : public CCSprite {
public:
    Enemywitcherbullet();
    ~Enemywitcherbullet();
    /*CREATE_FUNC(Bullet);*/
    static Enemywitcherbullet* createbullet();
    virtual bool init();

	void setAttack(INT32 _attack);

    void addNewBullet(Monsterwitcher* monsterwitcher);//增加一个新子弹 如果不行就换成坐标
    void moveBullet1(Monsterwitcher* monsterwitcher, Player* player);//移动子弹
    void moveBullet2(Monsterwitcher* monsterwitcher, Player* player);//移动子弹
    void moveBullet3(Monsterwitcher* monsterwitcher, Player* player);//移动子弹
    void moveBullet4(Monsterwitcher* monsterwitcher, Player* player);//移动子弹
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//保存所有已存在的子弹对象

    CCSprite* m_bulletSprite;//使用BatchNode构建所有的子弹

    void initData(Point pointPlayer);

    SpriteBatchNode* bulletBatchNode;//批次渲染节点
	INT32 bulletAttack = 5;
};


#endif


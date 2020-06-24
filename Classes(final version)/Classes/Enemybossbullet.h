#ifndef __Enemybossbullet_H__
#define __Enemybossbullet_H__

#include "cocos2d.h"
#include"Monsterwitcherboss.h"
#include"Entity.h"

USING_NS_CC;

USING_NS_CC;

class Player;
class Monsterwitcherboss;

class Enemybossbullet : public CCSprite {
public:
    Enemybossbullet();
    ~Enemybossbullet();
    /*CREATE_FUNC(Bullet);*/
    static Enemybossbullet* createbullet();
    virtual bool init();

	void setAttack(INT32 _attack);
    void addNewBullet(Monsterwitcherboss* monsterwitcherboss);//增加一个新子弹 如果不行就换成坐标
    void moveBullet1(Monsterwitcherboss* monsterwitcherboss, Player* player);//移动子弹
    void moveBullet2(Monsterwitcherboss* monsterwitcherboss, Player* player);//移动子弹
    void moveBullet3(Monsterwitcherboss* monsterwitcherboss, Player* player);//移动子弹
    void moveBullet4(Monsterwitcherboss* monsterwitcherboss, Player* player);//移动子弹
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//保存所有已存在的子弹对象

    CCSprite* m_bulletSprite;//使用BatchNode构建所有的子弹

    void initData(Point pointPlayer);

    SpriteBatchNode* bulletBatchNode;//批次渲染节点

	INT32 bulletAttack = 20;
};


#endif


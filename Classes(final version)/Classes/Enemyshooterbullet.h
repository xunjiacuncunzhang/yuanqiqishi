#ifndef __Enemyshooterbullet_H__
#define __Enemyshooterbullet_H__

#include "cocos2d.h"
#include"Monstershooter.h"
#include"Entity.h"

USING_NS_CC;

class Player;
class Monstershooter;
class Enemyshooterbullet: public CCSprite {
public:
    Enemyshooterbullet();
    ~Enemyshooterbullet();
    /*CREATE_FUNC(Bullet);*/
    static Enemyshooterbullet* createbullet();
    virtual bool init();

	void setAttack(INT32 _attack);

    void addNewBullet(Monstershooter*monster);//增加一个新子弹 如果不行就换成坐标
    void moveBullet( Monstershooter* monster, Player* player);//移动子弹
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//保存所有已存在的子弹对象

    CCSprite* m_bulletSprite;//使用BatchNode构建所有的子弹

    void initData(Point pointPlayer);
    
    SpriteBatchNode* bulletBatchNode;//批次渲染节点

	INT32 bulletAttack = 5;
};


#endif


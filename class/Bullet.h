
#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"
#include"weapon.h"
#include"Exp.h"

USING_NS_CC;

class Bullet : public CCSprite {
public:
    Bullet();
    ~Bullet();
    //CREATE_FUNC(Bullet);
    virtual void init(Point pointPlayer);

    void addNewBullet(weapon* weapon,Exp* exp);//增加一个新子弹 如果不行就换成坐标
    void moveBullet(Player* player, Monster *monster);//移动子弹
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//保存所有已存在的子弹对象

    CCSpriteBatchNode* m_bulletSprite;//使用BatchNode构建所有的子弹

    void initData(Point pointPlayer);
   

};


#endif



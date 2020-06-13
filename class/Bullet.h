/*
#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"

USING_NS_CC;

class Bullet : public CCLayer {
public:
    Bullet();
    ~Bullet();
    //CREATE_FUNC(Bullet);
    virtual void init(Point pointPlayer);

    void addNewBullet();//增加一个新子弹
    //void moveBullet(Player* player, Monster *monster);//移动子弹
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//保存所有已存在的子弹对象

    CCSpriteBatchNode* m_bulletSprite;//使用BatchNode构建所有的子弹

    void initData(Point pointPlayer);
   

};


#endif

*/

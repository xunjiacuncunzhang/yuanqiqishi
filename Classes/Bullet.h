
#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"
#include"weapon.h"

USING_NS_CC;

class Bullet : public CCSprite {
public:
    Bullet();
    ~Bullet();
    //CREATE_FUNC(Bullet);
    virtual void init(Point pointPlayer);

    void addNewBullet(weapon* weapon);//����һ�����ӵ� ������оͻ�������
    void moveBullet(Player* player, Monster *monster);//�ƶ��ӵ�
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//���������Ѵ��ڵ��ӵ�����

    CCSpriteBatchNode* m_bulletSprite;//ʹ��BatchNode�������е��ӵ�

    void initData(Point pointPlayer);
   

};


#endif



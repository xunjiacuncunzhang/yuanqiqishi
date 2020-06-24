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

    void addNewBullet(Monstershooter*monster);//����һ�����ӵ� ������оͻ�������
    void moveBullet( Monstershooter* monster, Player* player);//�ƶ��ӵ�
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//���������Ѵ��ڵ��ӵ�����

    CCSprite* m_bulletSprite;//ʹ��BatchNode�������е��ӵ�

    void initData(Point pointPlayer);
    
    SpriteBatchNode* bulletBatchNode;//������Ⱦ�ڵ�

	INT32 bulletAttack = 5;
};


#endif


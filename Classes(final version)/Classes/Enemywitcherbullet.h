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

    void addNewBullet(Monsterwitcher* monsterwitcher);//����һ�����ӵ� ������оͻ�������
    void moveBullet1(Monsterwitcher* monsterwitcher, Player* player);//�ƶ��ӵ�
    void moveBullet2(Monsterwitcher* monsterwitcher, Player* player);//�ƶ��ӵ�
    void moveBullet3(Monsterwitcher* monsterwitcher, Player* player);//�ƶ��ӵ�
    void moveBullet4(Monsterwitcher* monsterwitcher, Player* player);//�ƶ��ӵ�
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//���������Ѵ��ڵ��ӵ�����

    CCSprite* m_bulletSprite;//ʹ��BatchNode�������е��ӵ�

    void initData(Point pointPlayer);

    SpriteBatchNode* bulletBatchNode;//������Ⱦ�ڵ�
	INT32 bulletAttack = 5;
};


#endif


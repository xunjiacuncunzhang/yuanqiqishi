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
    void addNewBullet(Monsterwitcherboss* monsterwitcherboss);//����һ�����ӵ� ������оͻ�������
    void moveBullet1(Monsterwitcherboss* monsterwitcherboss, Player* player);//�ƶ��ӵ�
    void moveBullet2(Monsterwitcherboss* monsterwitcherboss, Player* player);//�ƶ��ӵ�
    void moveBullet3(Monsterwitcherboss* monsterwitcherboss, Player* player);//�ƶ��ӵ�
    void moveBullet4(Monsterwitcherboss* monsterwitcherboss, Player* player);//�ƶ��ӵ�
private:
    CCSize winSize;
    CCArray* m_allBulletArray;//���������Ѵ��ڵ��ӵ�����

    CCSprite* m_bulletSprite;//ʹ��BatchNode�������е��ӵ�

    void initData(Point pointPlayer);

    SpriteBatchNode* bulletBatchNode;//������Ⱦ�ڵ�

	INT32 bulletAttack = 20;
};


#endif


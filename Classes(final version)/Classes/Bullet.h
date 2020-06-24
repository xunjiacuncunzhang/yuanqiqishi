
#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"
#include"weapon.h"
#include"Player.h"
#include"Exp.h"
#include"Entity.h"

USING_NS_CC;

class weapon;
class Player;

class Bullet : public CCSprite {
public:
	Bullet();
	~Bullet();
	/*CREATE_FUNC(Bullet);*/
	static Bullet* createbullet();
	virtual bool init();

	void addNewBullet(Player *knight);//����һ�����ӵ� ������оͻ�������
	void moveBullet(Player* player, Entity* monster, INT32 attack, Exp* exp, weapon *weapon);//�ƶ��ӵ�
private:
	CCSize winSize;
	CCArray* m_allBulletArray;//���������Ѵ��ڵ��ӵ�����

	CCSprite* m_bulletSprite;//ʹ��BatchNode�������е��ӵ�

	void initData(Point pointPlayer);


};


#endif



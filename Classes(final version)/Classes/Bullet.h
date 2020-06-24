
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

	void addNewBullet(Player *knight);//增加一个新子弹 如果不行就换成坐标
	void moveBullet(Player* player, Entity* monster, INT32 attack, Exp* exp, weapon *weapon);//移动子弹
private:
	CCSize winSize;
	CCArray* m_allBulletArray;//保存所有已存在的子弹对象

	CCSprite* m_bulletSprite;//使用BatchNode构建所有的子弹

	void initData(Point pointPlayer);


};


#endif



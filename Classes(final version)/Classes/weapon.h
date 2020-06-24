#ifndef __weapon__
#define __weapon__

#include "cocos2d.h"
#include"Bullet.h"
#include"Exp.h"
#include"Player.h"
#include"Monsterwitcher.h"
#include"Entity.h"

USING_NS_CC;
class Bullet;
class Player;

class weapon : public CCSprite
{
public:
	weapon(void);
	~weapon(void);
	Bullet* bullet;
	static weapon* createWithFileName(char* name);//重载
	void InitweaponSprite();//在这里面加载子弹
	void setAttack(INT32 attack);
	INT32 getAttack();
	void setWeaponType(INT32 _type);
	INT32 getWeaponType();

	void isCollision(Player* player, Entity *monster);
	void makeRotate(Player*knight, Entity*monster);
	void rotateBack();
	void RotateWhileWalk(Point direction);

	//武器蓝条
	void setExpData(float data);
	float getExpData();
private:
	INT32 attack;

	INT32 type;

	float expData;//角色蓝条

};

#endif
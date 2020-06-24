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
	static weapon* createWithFileName(char* name);//����
	void InitweaponSprite();//������������ӵ�
	void setAttack(INT32 attack);
	INT32 getAttack();
	void setWeaponType(INT32 _type);
	INT32 getWeaponType();

	void isCollision(Player* player, Entity *monster);
	void makeRotate(Player*knight, Entity*monster);
	void rotateBack();
	void RotateWhileWalk(Point direction);

	//��������
	void setExpData(float data);
	float getExpData();
private:
	INT32 attack;

	INT32 type;

	float expData;//��ɫ����

};

#endif
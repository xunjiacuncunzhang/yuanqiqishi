#ifndef __weapon__
#define __weapon__

#include "cocos2d.h"
#include"Bullet.h"

USING_NS_CC;

class weapon : public CCSprite
{
public:
	weapon(void);
	~weapon(void);
	Bullet* bullet;
	static weapon* createWithFileName(char* name);//����
	void InitweaponSprite();//������������ӵ�
	void controlBullet(Player *qishi,Monster *monster);
private:
	
};

#endif
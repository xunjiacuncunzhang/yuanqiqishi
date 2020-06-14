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
	static weapon* createWithFileName(char* name);//重载
	void InitweaponSprite();//在这里面加载子弹
	void controlBullet(Player *qishi,Monster *monster);
private:
	
};

#endif
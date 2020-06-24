#ifndef __ENEMY_H__
#define __ENEMY_H__
#include"cocos2d.h"
#include"safemap.h"
#include"enemy.h"
USING_NS_CC;
class safemap;

class enemy :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void enemy1(Ref* pSender);
	void enemy2(Ref* pSendr);
	void enemy3(Ref* pSender);
	void enemy4(Ref* pSender);
	void hero(Ref* pSender);
	void back(Ref* pSender);
	void unlock(Ref* pSender);
	void send();
	CREATE_FUNC(enemy);
};
#endif

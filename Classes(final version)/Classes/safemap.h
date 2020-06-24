#ifndef __SAFEMAP_H__
#define __SAFEMAP_H__
#include "cocos2d.h"
#include"enemy.h"
#include"backpack.h"
#include"Player.h"
USING_NS_CC;
class JoyStick;
class enemy;

class safemap : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
   // implement the "static create()" method manually
	void back(Ref* pSender);
	void update(float dt);
	void bag(Ref* pSender);
	void set(Ref* pSneder);
	void pause(Ref* pSender);
	void book(Ref* pSender);
	CREATE_FUNC(safemap);
	static backpack myBag;

	void setHero(Player*player);

private:
	JoyStick* rocker;
	Player* knight;
};
#endif // __HELLOWORLD_SCENE_H__

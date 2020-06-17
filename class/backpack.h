#pragma once
#ifndef __BACKPACK_H__
#define __BACKPACK_H__
#include"cocos2d.h"
USING_NS_CC;
class backpack:public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void useredbottle(Ref* pSender);
	void usebluebottle(Ref* pSender);
	void add(int rednumber, int bluenumber);
	CREATE_FUNC(backpack);
private:
	int limit = 16;
};
#endif // !__BACKPACK_H__




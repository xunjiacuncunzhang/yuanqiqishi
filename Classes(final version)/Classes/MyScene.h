#ifndef __MYSCENE_H__
#define __MYSCENE_H__
#include"cocos2d.h"
class MyWorld :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void set(cocos2d::Ref* pSender);
	void pause(cocos2d::Ref* pSender);
	void start(cocos2d::Ref* pSender);
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(MyWorld);
};
#endif
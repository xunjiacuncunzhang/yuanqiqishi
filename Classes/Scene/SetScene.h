#ifndef __SETSCENE_H__
#define __SETSCENE_H__
#include"cocos2d.h"
#include"extensions/GUI/CCControlExtension/CCControlSlider.h"

USING_NS_CC;
using namespace ui;

class SetWorld :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void back(cocos2d::Ref* pSender);
	CREATE_FUNC(SetWorld);
};
#endif

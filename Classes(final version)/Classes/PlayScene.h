#pragma once
#ifndef PLAYSCENE_H_
#define PLAYSCENE_H_
#include "cocos2d.h"

#include"PlayLayer.h"
#include"KeyboardControl.h"
#include"Player.h"
#include"keyBoardDelegate.h"

USING_NS_CC;
class playLayer;

class PlayScene:public cocos2d::Scene
{
public:
	PlayScene();
	void reStart(Ref*psender);

	virtual bool init();
	CREATE_FUNC(PlayScene);

	CC_SYNTHESIZE(playLayer*, _playLayer, PlayLayer);
	CC_SYNTHESIZE(KeyboardControl*, _controlLayer, ControlLayer);

	static INT32 level;
	
};
#endif

//参考：原文链接：https://blog.csdn.net/akof1314/article/details/8549150
#pragma once
#ifndef GAME_PAUSE_
#define GAME_PAUSE_

#include "cocos2d.h"

USING_NS_CC;

class gamePause : public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* scene(cocos2d::RenderTexture* sqr);

	//������Ϸ
	void menuContinueCallback(Ref* pSender);
	//��������
	void menuLogin(Ref* pSender);
	
	CREATE_FUNC(gamePause);
};
#endif

//�ο���https://blog.csdn.net/evankaka/article/details/42936117
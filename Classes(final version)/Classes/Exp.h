#pragma once


#ifndef __Exp__
#define __Exp__

#include "cocos2d.h"

USING_NS_CC;
class Exp : public CCNode
{
public:
	Exp();
	~Exp();

public:
	//static ProgressViewBlood* createWithFileName(const char* name);//重载
	//设置血条背景
	void setBackgroundTexture(const char* pName);
	//设置血条前景
	void setForegroundTexture(const char* pName);
	//设置总血量
	void setTotalProgress(float total);
	//设置当前血量
	void setCurrentProgress(float progress);
	//得到当前血量
	float getCurrentProgress();
	//得到总血量
	float getTotalProgress();

	void setCurrentExp(float getexp);//加蓝或者减蓝 getexp可正可负
private:

	//设置前景血条显示的长度
	void setForegroundTextureRect(CCRect& rect);

private:
	CCSprite* ExpBackground;//背景血条
	CCSprite* ExpForeground;//前景血条
	float totalExp;//总血量
	float currentExp;//当前血量
	float m_scale;//放大倍数  可删
};


#endif


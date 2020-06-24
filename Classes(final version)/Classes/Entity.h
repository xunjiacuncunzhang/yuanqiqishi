#pragma once
#ifndef ENTITY_H_
#define ENTITY_H_
#include"cocos2d.h"
#include"ProgressViewBlood.h"

class Entity:public cocos2d::Sprite
{
public:
	virtual void setCurrentBlood(int blood)=0;
	int getCurrentBlood();
	virtual void attacked(int attack)=0;

	virtual void died()=0;

protected:
	int currentBlood;
};
#endif


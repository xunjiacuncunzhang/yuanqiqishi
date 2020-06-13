#pragma once
#ifndef PROP_H_
#define PROP_H_
#include"cocos2d.h"
#include"Player.h"

class prop:public cocos2d::Sprite
{
public:
	static prop* prop::createWithFileName(const char* name);
	bool init();

	void setPropData(INT32 data);
	INT32 getPropData();

	void useProp(Player*knight);
	/*void packUpProp();*/

private:
	Player* knight = NULL;

	INT32 propData = 0;
};

#endif
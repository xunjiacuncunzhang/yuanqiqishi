#pragma once
#ifndef __KEYBOARDDELEGATE_H__
#define __KEYBOARDDELEGATE_H__
#include"cocos2d.h"
class keyBoardDelegate
{
public:
	virtual void didChangeDirectionTo(cocos2d::CCPoint direction) = 0;
	virtual void isHoldingDirection(cocos2d::CCPoint direction) = 0;
};
#endif
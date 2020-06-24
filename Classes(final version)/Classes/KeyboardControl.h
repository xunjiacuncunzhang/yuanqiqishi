//实现物理键盘操控
#ifndef __KEYBOARDCONTROL_H__
#define __KEYBOARDCONTROL_H__

#include"cocos2d.h"
#include"keyBoardDelegate.h"

USING_NS_CC;

class keyBoardDelegate;

class KeyboardControl : public cocos2d::Layer
{
public:

	CREATE_FUNC(KeyboardControl);
	virtual bool init();
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
	void update(float delta) override;

	CC_SYNTHESIZE(keyBoardDelegate*, k_delegate, Delegate);
private:
	// 设置按键状态 
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keySituation;

	EventListenerKeyboard* listener;

};

#endif
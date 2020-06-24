#include "KeyboardControl.h"
#include "cocos2d.h"
#include"keyBoardDelegate.h"

USING_NS_CC;

bool KeyboardControl::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//创建监听事件
	this-> listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		keySituation[keyCode] = true;
		log("key pressed");
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		keySituation[keyCode] = false;
		log("key release");
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();

	return true;
}

bool KeyboardControl::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (keySituation[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

//按下按键后改变方向，我设想的距离改变由角色类来完成
void KeyboardControl::update(float delta)
{
	Node::update(delta);
	auto leftArrow = EventKeyboard::KeyCode::KEY_A;
	auto rightArrow = EventKeyboard::KeyCode::KEY_D;
	auto upArrow = EventKeyboard::KeyCode::KEY_W;
	auto downArrow = EventKeyboard::KeyCode::KEY_S;
	auto change= EventKeyboard::KeyCode::KEY_C;
	auto attack= EventKeyboard::KeyCode::KEY_K;

	Point direction;

	if (isKeyPressed(change))
	{
		direction = Vec2(0, 0);
		k_delegate->isHoldingDirection(direction);
		return;
	}

	if (isKeyPressed(attack))
	{
		direction = Vec2(2, 2);
		k_delegate->isHoldingDirection(direction);
		return;
	}

	if (isKeyPressed(leftArrow) && isKeyPressed(upArrow))
	{

		direction = Vec2(-1, 1);
	}
	else if (isKeyPressed(leftArrow) && isKeyPressed(downArrow))
	{

		direction = Vec2(-1, -1);
	}
	else if (isKeyPressed(rightArrow) && isKeyPressed(upArrow))
	{

		direction = Vec2(1, 1);
	}
	else if (isKeyPressed(rightArrow) && isKeyPressed(downArrow))
	{
		direction = Vec2(-1, -1);
	}
	else if (isKeyPressed(leftArrow))
	{

		direction = Vec2(-1, 0);
	}
	else if (isKeyPressed(rightArrow))
	{
		direction = Vec2(1, 0);
	}
	else if (isKeyPressed(upArrow))
	{

		direction = Vec2(0, 1);
	}
	else if (isKeyPressed(downArrow))
	{
		direction = Vec2(0, -1);
	}

	k_delegate->didChangeDirectionTo(direction);
}

	
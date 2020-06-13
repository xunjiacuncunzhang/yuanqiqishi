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

	/*int offSetX = 0;
	int offSetY = 0;*/
	//以上两行代表运动距离，可视情况加上

	Point direction;

	if (isKeyPressed(leftArrow) && isKeyPressed(upArrow))
	{
		/*offSetX = -2;
		offSetY = 2;*/

		direction = Vec2(-1, 1);
	}
	else if (isKeyPressed(leftArrow) && isKeyPressed(downArrow))
	{
		/*offSetX = -2;
		offSetY = -2;*/

		direction = Vec2(-1, -1);
	}
	else if (isKeyPressed(rightArrow) && isKeyPressed(upArrow))
	{
		/*offSetX = 2;
		offSetY = 2;*/

		direction = Vec2(1, 1);
	}
	else if (isKeyPressed(rightArrow) && isKeyPressed(downArrow))
	{
		/*offSetX = -2;
		offSetY = =2;*/

		direction = Vec2(-1, -1);
	}
	else if (isKeyPressed(leftArrow))
	{
		/*offSetX = -2;*/

		direction = Vec2(-1, 0);
	}
	else if (isKeyPressed(rightArrow))
	{
		/*offSetX = 2;*/

		direction = Vec2(1, 0);
	}
	else if (isKeyPressed(upArrow))
	{
		/*offSetY = 2;*/

		direction = Vec2(0, 1);
	}
	else if (isKeyPressed(downArrow))
	{
		/*offSetY = -2;*/

		direction = Vec2(0, -1);
	}

	/*auto moveTo = MoveTo::create(0.3, Vec2(knight->getPositionX() + offSetX, knight->getPositionY() + offSetY));
	knight->runAction(moveTo);*/

	k_delegate->didChangeDirectionTo(direction);
}

	
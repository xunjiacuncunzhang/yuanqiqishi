#include "Joystick.h"
using namespace cocos2d;

//����һ����ʱ������ʱ����������λ��
void HRocker::updatePos(float dt)
{
	jsSprite->setPosition(ccpAdd(jsSprite->getPosition(), ccpMult(ccpSub(currentPoint, jsSprite->getPosition()), 0.5)));
}

//����ҡ��
void HRocker::Active()
{
	if (!active) {
		active = true;
		schedule(schedule_selector(HRocker::updatePos));//���ˢ�º���
		//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
		touchListener = EventListenerTouchOneByOne::create();
		touchListener->setSwallowTouches(true);

		touchListener->onTouchBegan = CC_CALLBACK_2(HRocker::onTouchBegan, this);
		touchListener->onTouchMoved = CC_CALLBACK_2(HRocker::onTouchMoved, this);
		touchListener->onTouchEnded = CC_CALLBACK_2(HRocker::onTouchEnded, this);
		// ע���¼���������
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	}
	else {
	}
}
//���ҡ��
void HRocker::Inactive()
{
	if (active)
	{
		active = false;
		this->unschedule(schedule_selector(HRocker::updatePos));//ɾ��ˢ��
		_eventDispatcher->removeEventListener(touchListener);//ɾ��ί��
	}
	else
	{
	}
}

//ҡ�˷�λ
Vec2 HRocker::getDirection()
{
	return ccpNormalize(ccpSub(currentPoint, centerPoint));
}

//ҡ������
float HRocker::getVelocity()
{
	return ccpDistance(centerPoint, currentPoint);
}

HRocker* HRocker::HRockerWithCenter(Vec2 point, float aRadius, Sprite* aJsSprite, Sprite* aJsBg, bool _isFollowRole)
{
	HRocker* jstick = HRocker::create();
	jstick->initWithCenter(point, aRadius, aJsSprite, aJsBg, _isFollowRole);
	return jstick;
}

bool HRocker::onTouchBegan(Touch* touch, Event* event)
{
	if (!active)
		return false;
	this->setVisible(true);
	Vec2 touchPoint = touch->getLocationInView();
	touchPoint = Director::sharedDirector()->convertToGL(touchPoint);
	if (!isFollowRole)
	{
		if (ccpDistance(touchPoint, centerPoint) > radius) {
			return false;
		}
	}
	currentPoint = touchPoint;
	if (isFollowRole)
	{
		centerPoint = currentPoint;
		jsSprite->setPosition(currentPoint);
		this->getChildByTag(88)->setPosition(currentPoint);
	}
	return true;
}

void HRocker::onTouchMoved(Touch* touch, Event* event)
{
	Vec2 touchPoint = touch->getLocationInView();
	touchPoint = Director::sharedDirector()->convertToGL(touchPoint);
	if (ccpDistance(touchPoint, centerPoint) > radius)
	{
		currentPoint = ccpAdd(centerPoint, ccpMult(ccpNormalize(ccpSub(touchPoint, centerPoint)), radius));
	}
	else {
		currentPoint = touchPoint;
	}
}

void HRocker::onTouchEnded(Touch* touch, Event* event)
{
	currentPoint = centerPoint;
	if (isFollowRole) {
		this->setVisible(false);
	}
}
HRocker* HRocker::initWithCenter(Vec2 aPoint, float aRadius, Sprite* aJsSprite, Sprite* aJsBg, bool _isFollowRole) {
	isFollowRole = _isFollowRole;
	active = false;
	radius = aRadius;
	if (!_isFollowRole) {
		centerPoint = aPoint;
	}
	else {
		centerPoint = ccp(0, 0);
	}
	currentPoint = centerPoint;
	jsSprite = aJsSprite;
	jsSprite->setPosition(centerPoint);
	aJsBg->setPosition(centerPoint);
	aJsBg->setTag(88);
	aJsBg->setOpacity(100.0f);
	this->addChild(aJsBg);
	this->addChild(jsSprite);
	if (isFollowRole) {
		this->setVisible(false);
	}
	this->Active();//����ҡ��
	return this;
}

#ifndef HRocker_H
#define HRocker_H
#include "cocos2d.h"

using namespace cocos2d;

class HRocker :public Layer
{
public:
	//��ʼ�� aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���
	static HRocker* HRockerWithCenter(Vec2 point, float Radius, Sprite* aJsSprite, Sprite* aJsBg, bool _isFollowRole);
	//����ҡ��
	void Active();
	//���ҡ��
	void Inactive();
	// ��ȡҡ�˷�������
	Vec2 getDirection();
	// ��ȡҡ������
	float getVelocity();

private:
	EventListenerTouchOneByOne* touchListener;
	HRocker* initWithCenter(Vec2 point, float aRadius, Sprite* aJsSprite, Sprite* aJsBg, bool _isFollowRole);
	Vec2 centerPoint;//ҡ������
	Vec2 currentPoint;//ҡ�˵�ǰλ��
	bool active;//�Ƿ񼤻�ҡ��
	float radius;//ҡ�˰뾶
	Sprite* jsSprite;
	bool isFollowRole;//�Ƿ�����û����
	void updatePos(float dt);
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

	CREATE_FUNC(HRocker);
};

#endif

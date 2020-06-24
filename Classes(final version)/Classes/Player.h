#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
#include"ProgressViewBlood.h"
#include"weapon.h"
#include"Exp.h"
#include"Entity.h"

USING_NS_CC;
class weapon;

class Player :public Entity
{
public:
	Player(void);
	~Player(void);
	static Player* createWithFileName(const char*name);//����
	void InitPlayerSprite(char* xueback, char* xuefore);

	void setCurrentBlood(int blood);
	void attacked(int attack);
	void died();
	void setWeapon(weapon*newWeapon);
	weapon*& getWeapon();

	void init(Point point);
	int existLife;//����ʣ��Ѫ�� Ϊ�ٷ��� �Դ˿���Ѫ��
	//bool IsRunning();//�Ƿ��ܶ�
	//void StopAnimation();//�ܲ�����ֹͣ
	//bool Direction();

	void backToSafeMap();

	void update(float delta)override;
	void walkWithDirection(Point direction);
	CC_SYNTHESIZE(float, _walkSpeed, WalkSpeed);
	CC_SYNTHESIZE(cocos2d::CCPoint, _velocity, Velocity);
	CC_SYNTHESIZE(cocos2d::CCPoint, _desiredPosition, DesiredPosition);

	Exp* exp;//��ɫ����
	ProgressViewBlood * bloodView;

private:

	weapon* myWeapon;
};

#endif
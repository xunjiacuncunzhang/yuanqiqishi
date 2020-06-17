#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
#include"ProgressViewBlood.h"
#include"Exp.h"
USING_NS_CC;

class Player :public Sprite
{
public:
	Player(void);
	~Player(void);
	static Player* createWithFileName(char*name);//重载
	void InitPlayerSprite();
	void setCurrentBlood(int blood);
	int getCurrentBlood();
	void attacked(int attack);
	void died();
	void update(float delta);
	CCSprite* GetSprite();

	void init(Point point);
	int existLife;//人物剩余血量 为百分制 以此控制血条
	//bool IsRunning();//是否跑动
	//void StopAnimation();//跑步动画停止
	//bool Direction();

private:
	int currentBlood;
	CCSprite* m_MonsterSprite;//角色精灵

	char* Monster_name;//用来保存初始状态的精灵图片名称

	ProgressViewBlood * bloodView;//角色血条

	Exp* exp;//角色蓝条
};

#endif
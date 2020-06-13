#ifndef __Monstershooter_H__
#define __Monstershooter_H__
#include "cocos2d.h"
#include "ProgressView.h"
USING_NS_CC;
class Monstershooter :public cocos2d::CCNode
{
public:
	Monstershooter(void);
	~Monstershooter(void);
	//根据图片名创建怪物，不带血条
	void InitMonstershooterSprite(char* name);
	//带血条的怪物 
	void InitMonstershooterSprite(char* name, char* xue_back, char* xue_fore);
	//设置动画,num为图片数目，run_directon为精灵脸朝向，false朝右,name_each为name_png中每一小张图片的公共名称部分
	void SetAnimation(const char* name_each, const unsigned int num, bool run_directon);
	//停止动画
	void StopAnimation();
	//攻击动画
	void AttackAnimation(const char* name_each, const unsigned int num, bool run_directon);
	//攻击动画结束
	void AttackEnd();
	//返回英雄
	CCSprite* GetSprite();
	//判断是否在跑动画
	bool IsRunning;
	//判断是否在攻击动画
	bool IsAttack;
	//英雄运动的方向
	bool MonstershooterDirecton;

	void FollowRun(CCNode* m_hero, CCNode* m_map);
	//判断是否攻击
	void JudegeAttack();
	//怪物巡逻路线
	void MonsterSeeRun();

	//怪物启动监听英雄
	void StartListen(CCNode* m_hero, CCNode* m_map);
	//监听函数,每隔3秒检测下，计算英雄与怪物的距离
	void updateMonster(float delta);
	//更新函数，如果英雄在可视范围内，不断触发
	void update(float delta);

	CREATE_FUNC(Monstershooter);
private:
	Sprite* m_MonstershooterSprite;//怪物精灵
	char* Monster_name;//用来保存初始状态的精灵图片名称
	ProgressView* Monster_xue;//怪物血条

	CCNode* my_hero;//当前英雄
	CCNode* my_map;//当前地图
	float   dis;//当前怪物和英雄的距离

};
#endif // __HERO_H__


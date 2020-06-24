#pragma once
#ifndef __Monsterwitcherboss_H__
#define __Monsterwitcherboss_H__
#include "cocos2d.h"
#include "ProgressViewBlood.h"
#include"Enemybossbullet.h"
#include"Entity.h"
USING_NS_CC;

class Enemybossbullet;

class Monsterwitcherboss :public Entity
{
public:
	Monsterwitcherboss(void);
	~Monsterwitcherboss(void);
	//����ͼƬ�������������Ѫ��
	static Monsterwitcherboss* createWithFileName(const char* name);//����

	void initMonsterwitcherbossSprite(char* xueback, char* xuefore);
	virtual void setCurrentBlood(int blood);
	virtual void attacked(int attack);//�ܵ�����
	virtual void died();//����

	//���ö���,numΪͼƬ��Ŀ��run_directonΪ����������false����,name_eachΪname_png��ÿһС��ͼƬ�Ĺ������Ʋ���
	void SetAnimation(const char* name_each, const unsigned int num, bool run_directon);
	//ֹͣ����
	void StopAnimation();
	//��������
	void AttackAnimation(const char* name_each, const unsigned int num, bool run_directon);
	//������������
	void AttackEnd();
	//����Ӣ��
	CCSprite* GetSprite();
	//�ж��Ƿ����ܶ���
	bool IsRunning;
	//�ж��Ƿ��ڹ�������
	bool IsAttack;
	//Ӣ���˶��ķ���
	bool MonsterwitcherDirecton;

	void FollowRun(Sprite* m_hero, TMXTiledMap* m_map);
	//�ж��Ƿ񹥻�
	void JudegeAttack();
	//����Ѳ��·��
	void MonsterSeeRun();

	//������������Ӣ��
	void StartListen(Sprite* m_hero, TMXTiledMap* m_map);
	//��������,ÿ��3�����£�����Ӣ�������ľ���
	void updateMonster(float delta);
	//���º��������Ӣ���ڿ��ӷ�Χ�ڣ����ϴ���
	void update(float delta);

	CREATE_FUNC(Monsterwitcherboss);
	int existLife;

	Enemybossbullet* bulletU;
	Enemybossbullet* bulletR;
	Enemybossbullet* bulletL;
	Enemybossbullet* bulletD;

private:
	Sprite* m_MonsterwitcherbossSprite;//���ﾫ��
	char* Monster_name;//���������ʼ״̬�ľ���ͼƬ����
	ProgressViewBlood* bloodView;
	Sprite* my_hero;//��ǰӢ��
	TMXTiledMap* my_map;//��ǰ��ͼ
	float   dis;//��ǰ�����Ӣ�۵ľ���

};
#endif // __HERO_H__
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
	static Player* createWithFileName(char*name);//����
	void InitPlayerSprite();
	void setCurrentBlood(int blood);
	int getCurrentBlood();
	void attacked(int attack);
	void died();
	void update(float delta);
	CCSprite* GetSprite();

	void init(Point point);
	int existLife;//����ʣ��Ѫ�� Ϊ�ٷ��� �Դ˿���Ѫ��
	//bool IsRunning();//�Ƿ��ܶ�
	//void StopAnimation();//�ܲ�����ֹͣ
	//bool Direction();

private:
	int currentBlood;
	CCSprite* m_MonsterSprite;//��ɫ����

	char* Monster_name;//���������ʼ״̬�ľ���ͼƬ����

	ProgressViewBlood * bloodView;//��ɫѪ��

	Exp* exp;//��ɫ����
};

#endif
#ifndef __Monsterwitcher_H__
#define __Monsterwitcher_H__
#include "cocos2d.h"
#include "ProgressViewBlood.h"
#include"Enemywitcherbullet.h"
#include"Entity.h"
USING_NS_CC;
class Enemywitcherbullet;

class Monsterwitcher :public Entity
{
public:
	Monsterwitcher(void);
	~Monsterwitcher(void);
	//����ͼƬ�������������Ѫ��
	static Monsterwitcher* createWithFileName(const char* name);//����

	void initMonsterwitcherSprite(char* xueback, char* xuefore);
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

	CREATE_FUNC(Monsterwitcher);
	int existLife;

	Enemywitcherbullet* bulletU;
	Enemywitcherbullet* bulletR;
	Enemywitcherbullet* bulletL;
	Enemywitcherbullet* bulletD;

private:
	Sprite* m_MonsterwitcherSprite;//���ﾫ��
	char* Monster_name;//���������ʼ״̬�ľ���ͼƬ����
	int currentBlood;
	ProgressViewBlood* bloodView;
	Sprite* my_hero;//��ǰӢ��
	TMXTiledMap* my_map;//��ǰ��ͼ
	float   dis;//��ǰ�����Ӣ�۵ľ���

};
#endif // __HERO_H__

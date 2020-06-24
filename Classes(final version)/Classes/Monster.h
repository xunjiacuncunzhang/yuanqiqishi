#ifndef __Monster_H__
#define __Monster_H__
#include "cocos2d.h"
#include "ProgressViewBlood.h"
#include"Entity.h"
USING_NS_CC;
class Monster :public Entity
{
public:
	Monster(void);
	~Monster(void);
	//����ͼƬ�������������Ѫ��
	static Monster* createWithFileName(const char* name);//����

	void initMonsterSprite(char* xueback, char* xuefore);
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
	bool MonsterDirecton;

	void FollowRun(CCNode* m_hero, CCNode* m_map);
	//�ж��Ƿ񹥻�
	void JudegeAttack();
	//����Ѳ��·��
	void MonsterSeeRun();

	//������������Ӣ��
	void StartListen(CCNode* m_hero, CCNode* m_map);
	//��������,ÿ��3�����£�����Ӣ�������ľ���
	void updateMonster(float delta);
	//���º��������Ӣ���ڿ��ӷ�Χ�ڣ����ϴ���
	void update(float delta);

	CREATE_FUNC(Monster);
private:
	Sprite* m_MonsterSprite;//���ﾫ��
	char* Monster_name;//���������ʼ״̬�ľ���ͼƬ����
	ProgressViewBlood* bloodView;

	CCNode* my_hero;//��ǰӢ��
	CCNode* my_map;//��ǰ��ͼ
	float   dis;//��ǰ�����Ӣ�۵ľ���

};
#endif // __HERO_H__


#ifndef __Monsterwitcher_H__
#define __Monsterwitcher_H__
#include "cocos2d.h"
#include "ProgressView.h"
USING_NS_CC;
class Monsterwitcher :public cocos2d::CCNode
{
public:
	Monsterwitcher(void);
	~Monsterwitcher(void);
	//����ͼƬ�������������Ѫ��
	void InitMonsterwitcherSprite(char* name);
	//��Ѫ���Ĺ��� 
	void InitMonsterwitcherSprite(char* name, char* xue_back, char* xue_fore);
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

	CREATE_FUNC(Monsterwitcher);
private:
	Sprite* m_MonsterwitcherSprite;//���ﾫ��
	char* Monster_name;//���������ʼ״̬�ľ���ͼƬ����
	ProgressView* Monster_xue;//����Ѫ��

	CCNode* my_hero;//��ǰӢ��
	CCNode* my_map;//��ǰ��ͼ
	float   dis;//��ǰ�����Ӣ�۵ľ���

};
#endif // __HERO_H__
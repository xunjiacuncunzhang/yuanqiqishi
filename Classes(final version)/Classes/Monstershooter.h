#ifndef __Monstershooter_H__
#define __Monstershooter_H__
#include "cocos2d.h"
#include "ProgressViewBlood.h"
#include"Enemyshooterbullet.h"
#include"Entity.h"
USING_NS_CC;
class Enemyshooterbullet;

class Monstershooter : public Entity
{
public:
	Monstershooter(void);
	~Monstershooter(void);
	//����ͼƬ�������������Ѫ��
	static Monstershooter* createWithFileName(const char* name);//����

	void initMonstershooterSprite(char* xueback, char* xuefore);
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
	bool MonstershooterDirecton;

	void FollowRun(CCNode* m_hero, CCNode* m_map);
	//�ж��Ƿ񹥻�
	void JudegeAttack();
	//����Ѳ��·��
	void MonsterSeeRun();

	//������������Ӣ��
	void StartListen(Sprite* m_hero, CCNode* m_map);
	//��������,ÿ��3�����£�����Ӣ�������ľ���
	void updateMonster(float delta);
	//���º��������Ӣ���ڿ��ӷ�Χ�ڣ����ϴ���
	//void update(float delta);

	CREATE_FUNC(Monstershooter);

	Enemyshooterbullet* bullet;
private:
	Sprite* m_MonstershooterSprite;//���ﾫ��
	char* Monster_name;//����Ѫ��
	ProgressViewBlood* bloodView;
	
	CCNode* my_hero;//��ǰӢ��
	CCNode* my_map;//��ǰ��ͼ
	float   dis;//��ǰ�����Ӣ�۵ľ���

};
#endif //

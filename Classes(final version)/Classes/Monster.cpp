#include "Monster.h"
USING_NS_CC;
Monster::Monster(void)
{
	IsRunning = false;//û�ڷŶ���
	MonsterDirecton = TRUE;//�����˶�
	Monster_name = NULL;
	IsAttack = false;
	
}
Monster::~Monster(void)
{

}
CCSprite* Monster::GetSprite()
{
	return m_MonsterSprite;
}
Monster* Monster::createWithFileName(const char* name)//����create
{
	Monster* pobMonster = new Monster();
	if (pobMonster && pobMonster->initWithFile(name))
	{
		pobMonster->autorelease();
		return pobMonster;
	}
	CC_SAFE_DELETE(pobMonster);
	return NULL;

}
void Monster::initMonsterSprite(char* xueback, char* xuefore)
{
	//���ù����Ѫ�� 
	bloodView = new ProgressViewBlood();
	bloodView->setPosition(ccp(this->getPositionX(), this->getPositionY() + 50));//�����ڹ�����ͷ  
	bloodView->setScale(2.2f);
	bloodView->setBackgroundTexture("bloodOutside.png");
	bloodView->setForegroundTexture("blood.png");
	bloodView->setTotalProgress(100.0f);
	bloodView->setCurrentProgress(100.0f);
	this->addChild(bloodView, 2);

}


void Monster::setCurrentBlood(int blood) {
	currentBlood = blood;
	bloodView->setCurrentProgress(blood);
}

void Monster::attacked(int attack) {
	currentBlood = currentBlood - attack;
	bloodView->setCurrentProgress(bloodView->getCurrentProgress() - attack);
}
void Monster::died() 
{
	if (currentBlood == 0)
	{
		this->removeChild(m_MonsterSprite, TRUE);//�ѹ���ɾ����
	}
}


void  Monster::SetAnimation(const char* name_each, unsigned int num, bool run_directon)
{
	if (MonsterDirecton != run_directon)
	{
		MonsterDirecton = run_directon;
		m_MonsterSprite->setFlipX(run_directon);
	}
	if (IsRunning || IsAttack)
		return;
	CCAnimation* animation = CCAnimation::create();
	for (int i = 1; i <= num; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "%s%d.png", name_each, i);
		animation->addSpriteFrameWithFileName(szName); //���ض�����֡  
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(-1); //����ѭ��
	//��������װ��һ������
	CCAnimate* act = CCAnimate::create(animation);
	m_MonsterSprite->runAction(act);
	IsRunning = true;

}
void  Monster::StopAnimation()
{
	if (!IsRunning)
		return;
	m_MonsterSprite->stopAllActions();//��ǰ����ֹͣ���ж���
	//�ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_MonsterSprite, TRUE);//��ԭ���ľ���ɾ����
	m_MonsterSprite = CCSprite::create(Monster_name);//�ָ�����ԭ������ͼ����
	m_MonsterSprite->setFlipX(MonsterDirecton);
	this->addChild(m_MonsterSprite);
	IsRunning = false;
}
void  Monster::AttackAnimation(const char* name_each, const unsigned int num, bool run_directon)
{
	if (IsAttack || IsRunning)
		return;
	CCAnimation* animation = CCAnimation::create();
	for (int i = 1; i <= num; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "%s%d.png", name_each, i);
		animation->addSpriteFrameWithFileName(szName); //���ض�����֡  
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1); //����ѭ��1��  
	//��������װ��һ������
	CCAnimate* act = CCAnimate::create(animation);
	//�����ص��������������������AttackEnd()
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monster::AttackEnd));
	//������������
	CCActionInterval* attackact = CCSequence::create(act, callFunc, NULL);

	m_MonsterSprite->runAction(attackact);
	IsAttack = true;

}
void Monster::AttackEnd()
{
	//�ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_MonsterSprite, TRUE);//��ԭ���ľ���ɾ����
	m_MonsterSprite = CCSprite::create(Monster_name);//�ָ�����ԭ������ͼ����
	m_MonsterSprite->setFlipX(MonsterDirecton);
	this->addChild(m_MonsterSprite);
	IsAttack = false;
}


void Monster::FollowRun(CCNode* m_hero, CCNode* m_map)
{
	//�õ�����x�ľ���,�ǵù��������Ҫ���ϵ�ͼ��
	float x = m_hero->getPositionX() - (this->getPositionX() + m_map->getPositionX());
	//�õ�����y�ľ��룬�ǵù��������Ҫ���ϵ�ͼ��
	float y = m_hero->getPositionY() - (this->getPositionY() + m_map->getPositionY());

	//�ȼ�������Ӣ�۵ľ���
	dis = sqrt(pow(x, 2) + pow(y, 2));

	if (dis >= 30)//��������Ӣ�۾��볬��300
		return;
	if (dis <= 10)//�ڹ��﹥����Χ�ڣ�����ֹͣ�ƶ�
	{
		this->StopAnimation();//ֹͣ�ܶ�
		JudegeAttack();//��һ���ĸ����ж����Ƿ��������
		return;
	}

	if (x < -10)//�жϹ���������Ӣ�۵ľ���
	{

		MonsterDirecton = true;
		m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() - 1, this->getPositionY());//������Ӣ���ƶ�
		this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���

	}
	else if (x > 10)
	{

		MonsterDirecton = false;
		m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() + 1, this->getPositionY());
		this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���
	}
	else if (x <= 10)//����M���˺�Ӣ�������100����ʱ����ʼ�ƶ�����������
	{

		if (m_hero->getPositionY() > this->getPositionY())
		{
			m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() + 1);
			this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���
		}
		else if (m_hero->getPositionY() < this->getPositionY())
		{
			m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() - 1);
			this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���
		}
	}

}
void Monster::JudegeAttack()
{
	srand((UINT)GetCurrentTime());
	int x = rand() % 100;
	if (x > 98)
	{
		this->AttackAnimation("monster_attack", 5, MonsterDirecton);
	}

}
void  Monster::MonsterSeeRun()
{
	if (dis < 30)
		return;
	this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���
	CCMoveBy* moveby1;
	if (MonsterDirecton == true)
		moveby1 = CCMoveBy::create(2, ccp(-10, 0));
	else
		moveby1 = CCMoveBy::create(2, ccp(10, 0));
	//�����ص�������Ѳ��·�����
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monster::StopAnimation));
	//������������
	CCActionInterval* xunluo = CCSequence::create(moveby1, callFunc, NULL);
	this->runAction(xunluo);
}
//��������
void Monster::StartListen(CCNode* m_hero, CCNode* m_map)
{
	my_hero = m_hero;
	my_map = m_map;
	this->schedule(schedule_selector(Monster::updateMonster), 3.0f);//ÿ��3��������
	this->scheduleUpdate();//Ӣ��һ��������ӷ�Χ������׷��Ӣ�۴�
}
//��������,ÿ��3������
void Monster::updateMonster(float delta)
{
	//�õ�����x�ľ���,�ǵù��������Ҫ���ϵ�ͼ��
	float x = my_hero->getPositionX() - (this->getPositionX() + my_map->getPositionX());
	//�õ�����y�ľ��룬�ǵù��������Ҫ���ϵ�ͼ��
	float y = my_hero->getPositionY() - (this->getPositionY() + my_map->getPositionY());
	//�ȼ�������Ӣ�۵ľ���
	dis = sqrt(pow(x, 2) + pow(y, 2));
	if (dis >= 300)
	{
		if (!IsRunning)
			MonsterSeeRun();
	}
}
void Monster::update(float delta)
{
	if (dis < 30)///��Ӣ�������Ŀ��ӷ�Χ�ڣ�����׷��Ӣ��
		FollowRun(my_hero, my_map);
}


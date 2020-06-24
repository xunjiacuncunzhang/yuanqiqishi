#include "Monsterwitcher.h"
USING_NS_CC;
Monsterwitcher::Monsterwitcher(void)
{
	IsRunning = false;//û�ڷŶ���
	MonsterwitcherDirecton = TRUE;//�����˶�
	Monster_name = NULL;
	IsAttack = false;
}

Monsterwitcher::~Monsterwitcher(void)
{

}
CCSprite* Monsterwitcher::GetSprite()
{
	return m_MonsterwitcherSprite;
}
Monsterwitcher* Monsterwitcher::createWithFileName(const char* name)//����create
{
	Monsterwitcher* pobMonsterwitcher = new Monsterwitcher();
	if (pobMonsterwitcher && pobMonsterwitcher->initWithFile(name))
	{
		pobMonsterwitcher->autorelease();
		return pobMonsterwitcher;
	}
	CC_SAFE_DELETE(pobMonsterwitcher);
	return NULL;

}
void Monsterwitcher::initMonsterwitcherSprite( char* xueback, char* xuefore)
{
	//���ù����Ѫ�� 
	bloodView = new ProgressViewBlood();
	bloodView->setPosition(ccp(this->getPositionX(), this->getPositionY() + 50));//�����ڹ�����ͷ  
	bloodView->setScale(2.2f);
	bloodView->setBackgroundTexture("bloodOutside.png");
	bloodView->setForegroundTexture("blood.png");
	bloodView->setTotalProgress(100.0f);
	bloodView->setCurrentProgress(100.0f);
	this->addChild(bloodView,2);
	
}


void Monsterwitcher::setCurrentBlood(int blood) {
	currentBlood = blood;
	bloodView->setCurrentProgress(blood);
}

void Monsterwitcher::attacked(int attack) {
	currentBlood = currentBlood - attack;
	bloodView->setCurrentProgress(bloodView->getCurrentProgress() - attack);
}

void  Monsterwitcher::SetAnimation(const char* name_each, unsigned int num, bool run_directon)
{
	if (MonsterwitcherDirecton != run_directon)
	{
		MonsterwitcherDirecton = run_directon;
		m_MonsterwitcherSprite->setFlipX(run_directon);
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
	m_MonsterwitcherSprite->runAction(act);
	IsRunning = true;

}
void  Monsterwitcher::StopAnimation()
{
	if (!IsRunning)
		return;
	m_MonsterwitcherSprite->stopAllActions();//��ǰ����ֹͣ���ж���
	//�ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_MonsterwitcherSprite, TRUE);//��ԭ���ľ���ɾ����
	m_MonsterwitcherSprite = CCSprite::create(Monster_name);//�ָ�����ԭ������ͼ����
	m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);
	this->addChild(m_MonsterwitcherSprite);
	IsRunning = false;
}
void  Monsterwitcher::AttackAnimation(const char* name_each, const unsigned int num, bool run_directon)
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
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monsterwitcher::AttackEnd));
	//������������
	CCActionInterval* attackact = CCSequence::create(act, callFunc, NULL);
	m_MonsterwitcherSprite->runAction(attackact);
	IsAttack = true;

}
void Monsterwitcher::AttackEnd()
{
	//�ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_MonsterwitcherSprite, TRUE);//��ԭ���ľ���ɾ����
	m_MonsterwitcherSprite = CCSprite::create(Monster_name);//�ָ�����ԭ������ͼ����
	m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);
	this->addChild(m_MonsterwitcherSprite);
	IsAttack = false;
}

/*void Monsterwitcher::attacked(int attack) {
	currentBlood = currentBlood - attack;
	bloodView->setCurrentProgress(bloodView->getCurrentProgress() - attack);
}*/

void Monsterwitcher::died() 
{

	this->bulletD->setAttack(0);
	this->bulletD->setVisible(false);

	this->bulletU->setAttack(0);
	this->bulletU->setVisible(false);
	this->bulletL->setAttack(0);
	this->bulletL->setVisible(false);
	this->bulletR->setAttack(0);
	this->bulletR->setVisible(false);

	this->removeChild(m_MonsterwitcherSprite, TRUE);//��ԭ���ľ���ɾ����
}


void Monsterwitcher::FollowRun(Sprite* m_hero, TMXTiledMap* m_map)
{
	//�õ�����x�ľ���,�ǵù��������Ҫ���ϵ�ͼ��
	float x = m_hero->getPositionX() - (this->getPositionX() + m_map->getPositionX());
	//�õ�����y�ľ��룬�ǵù��������Ҫ���ϵ�ͼ��
	float y = m_hero->getPositionY() - (this->getPositionY() + m_map->getPositionY());

	//�ȼ�������Ӣ�۵ľ���
	dis = sqrt(pow(x, 2) + pow(y, 2));

	if (dis >= 300)//��������Ӣ�۾��볬��300
		return;
	if (dis <= 100)//�ڹ��﹥����Χ�ڣ�����ֹͣ�ƶ�
	{
		this->StopAnimation();//ֹͣ�ܶ�
		JudegeAttack();//��һ���ĸ����ж����Ƿ��������
		return;
	}

	if (x < -100)//�жϹ���������Ӣ�۵ľ���
	{

		MonsterwitcherDirecton = true;
		m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//���÷���
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() - 1, this->getPositionY());//������Ӣ���ƶ�
		this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//���Ŷ���

	}
	else if (x > 100)
	{

		MonsterwitcherDirecton = false;
		m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//���÷���
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() + 1, this->getPositionY());
		this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//���Ŷ���
	}
	else if (x <= 100)//����M���˺�Ӣ�������100����ʱ����ʼ�ƶ�����������
	{

		if (m_hero->getPositionY() > this->getPositionY())
		{
			m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//���÷���
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() + 1);
			this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//���Ŷ���
		}
		else if (m_hero->getPositionY() < this->getPositionY())
		{
			m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//���÷���
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() - 1);
			this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//���Ŷ���
		}
	}

}
void Monsterwitcher::JudegeAttack()
{
	srand((UINT)GetCurrentTime());
	int x = rand() % 100;
	if (x > 98)
	{
		this->AttackAnimation("monster_attack", 1, MonsterwitcherDirecton);
	}

}
void  Monsterwitcher::MonsterSeeRun()
{
	if (dis < 300)
		return;
	this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//���Ŷ���
	CCMoveBy* moveby1;
	if (MonsterwitcherDirecton == true)
		moveby1 = CCMoveBy::create(2, ccp(-10, 0));
	else
		moveby1 = CCMoveBy::create(2, ccp(10, 0));
	//�����ص�������Ѳ��·�����
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monsterwitcher::StopAnimation));
	//������������
	CCActionInterval* xunluo = CCSequence::create(moveby1, callFunc, NULL);
	this->runAction(xunluo);
}
//��������
void Monsterwitcher::StartListen(Sprite* m_hero, TMXTiledMap* m_map)
{
	my_hero = m_hero;
	my_map = m_map;
	this->schedule(schedule_selector(Monsterwitcher::updateMonster), 3.0f);//ÿ��3��������
	this->scheduleUpdate();//Ӣ��һ��������ӷ�Χ������׷��Ӣ�۴�
}
//��������,ÿ��3������
void Monsterwitcher::updateMonster(float delta)
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
void Monsterwitcher::update(float delta)
{
	if (dis < 300)///��Ӣ�������Ŀ��ӷ�Χ�ڣ�����׷��Ӣ��
		FollowRun(my_hero, my_map);
}


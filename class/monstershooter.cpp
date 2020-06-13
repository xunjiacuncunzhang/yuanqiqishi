#include "Monstershooter.h"
USING_NS_CC;
Monstershooter::Monstershooter(void)
{
	IsRunning = false;//没在放动画
	MonstershooterDirecton = TRUE;//向右运动
	Monster_name = NULL;
	IsAttack = false;
	Monster_xue = NULL;
}

Monstershooter::~Monstershooter(void)
{

}
CCSprite* Monstershooter::GetSprite()
{
	return m_MonstershooterSprite;
}
void  Monstershooter::InitMonstershooterSprite(char* name)
{
	Monster_name = name;
	this->m_MonstershooterSprite = CCSprite::create(name);
	m_MonstershooterSprite->setFlipX(MonstershooterDirecton);
	this->addChild(m_MonstershooterSprite);
}
void Monstershooter::InitMonstershooterSprite(char* name, char* xue_back, char* xue_fore)
{
	InitMonstershooterSprite(name);
	//设置怪物的血条 
	Monster_xue = new ProgressView();
	Monster_xue->setPosition(ccp(m_MonstershooterSprite->getPositionX() + 25, m_MonstershooterSprite->getPositionY() + 50));//设置在怪物上头  
	//Monster_xue->setScale(2.2f);  
	Monster_xue->setBackgroundTexture(xue_back);
	Monster_xue->setForegroundTexture(xue_fore);
	Monster_xue->setTotalProgress(300.0f);
	Monster_xue->setCurrentProgress(300.0f);
	this->addChild(Monster_xue);
}
void  Monstershooter::SetAnimation(const char* name_each, unsigned int num, bool run_directon)
{
	if (MonstershooterDirecton != run_directon)
	{
		MonstershooterDirecton = run_directon;
		m_MonstershooterSprite->setFlipX(run_directon);
	}
	if (IsRunning || IsAttack)
		return;
	CCAnimation* animation = CCAnimation::create();
	for (int i = 1; i <= num; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "%s%d.png", name_each, i);
		animation->addSpriteFrameWithFileName(szName); //加载动画的帧  
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(-1); //动画循环
	//将动画包装成一个动作
	CCAnimate* act = CCAnimate::create(animation);
	m_MonstershooterSprite->runAction(act);
	IsRunning = true;

}
void  Monstershooter::StopAnimation()
{
	if (!IsRunning)
		return;
	m_MonstershooterSprite->stopAllActions();//当前精灵停止所有动画
	//恢复精灵原来的初始化贴图 
	this->removeChild(m_MonstershooterSprite, TRUE);//把原来的精灵删除掉
	m_MonstershooterSprite = CCSprite::create(Monster_name);//恢复精灵原来的贴图样子
	m_MonstershooterSprite->setFlipX(MonstershooterDirecton);
	this->addChild(m_MonstershooterSprite);
	IsRunning = false;
}
void  Monstershooter::AttackAnimation(const char* name_each, const unsigned int num, bool run_directon)
{
	if (IsAttack || IsRunning)
		return;
	CCAnimation* animation = CCAnimation::create();
	for (int i = 1; i <= num; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "%s%d.png", name_each, i);
		animation->addSpriteFrameWithFileName(szName); //加载动画的帧  
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1); //动画循环1次  
	//将动画包装成一个动作
	CCAnimate* act = CCAnimate::create(animation);
	//创建回调动作，攻击结束后调用AttackEnd()
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monstershooter::AttackEnd));
	//创建连续动作
	CCActionInterval* attackact = CCSequence::create(act, callFunc, NULL);
	m_MonstershooterSprite->runAction(attackact);
	IsAttack = true;

}
void Monstershooter::AttackEnd()
{
	//恢复精灵原来的初始化贴图 
	this->removeChild(m_MonstershooterSprite, TRUE);//把原来的精灵删除掉
	m_MonstershooterSprite = CCSprite::create(Monster_name);//恢复精灵原来的贴图样子
	m_MonstershooterSprite->setFlipX(MonstershooterDirecton);
	this->addChild(m_MonstershooterSprite);
	IsAttack = false;
}


void Monstershooter::FollowRun(CCNode* m_hero, CCNode* m_map)
{
	//得到两点x的距离,记得怪物的坐标要加上地图的
	float x = m_hero->getPositionX() - (this->getPositionX() + m_map->getPositionX());
	//得到两点y的距离，记得怪物的坐标要加上地图的
	float y = m_hero->getPositionY() - (this->getPositionY() + m_map->getPositionY());

	//先计算怪物和英雄的距离
	dis = sqrt(pow(x, 2) + pow(y, 2));

	if (dis >= 30)//当怪物与英雄距离超过300
		return;
	if (dis <= 10)//在怪物攻击范围内，怪物停止移动
	{
		this->StopAnimation();//停止跑动
		JudegeAttack();//以一定的概率判断是是否出动攻击
		return;
	}

	if (x < -10)//判断怪物横坐标和英雄的距离
	{

		MonstershooterDirecton = true;
		m_MonstershooterSprite->setFlipX(MonstershooterDirecton);//设置方向
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() - 1, this->getPositionY());//怪物向英雄移动
		this->SetAnimation("monster_run", 6, MonstershooterDirecton);//播放动画

	}
	else if (x > 10)
	{

		MonstershooterDirecton = false;
		m_MonstershooterSprite->setFlipX(MonstershooterDirecton);//设置方向
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() + 1, this->getPositionY());
		this->SetAnimation("monster_run", 6, MonstershooterDirecton);//播放动画
	}
	else if (x <= 10)//怪物橫坐標和英雄相差在100以内时，开始移动怪物纵坐标
	{

		if (m_hero->getPositionY() > this->getPositionY())
		{
			m_MonstershooterSprite->setFlipX(MonstershooterDirecton);//设置方向
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() + 1);
			this->SetAnimation("monster_run", 6, MonstershooterDirecton);//播放动画
		}
		else if (m_hero->getPositionY() < this->getPositionY())
		{
			m_MonstershooterSprite->setFlipX(MonstershooterDirecton);//设置方向
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() - 1);
			this->SetAnimation("monster_run", 6, MonstershooterDirecton);//播放动画
		}
	}

}
void Monstershooter::JudegeAttack()
{
	srand((UINT)GetCurrentTime());
	int x = rand() % 100;
	if (x > 98)
	{
		this->AttackAnimation("monster_attack", 5, MonstershooterDirecton);
	}

}
void  Monstershooter::MonsterSeeRun()
{
	if (dis < 30)
		return;
	this->SetAnimation("monster_run", 6, MonstershooterDirecton);//播放动画
	CCMoveBy* moveby1;
	if (MonstershooterDirecton == true)
		moveby1 = CCMoveBy::create(2, ccp(-10, 0));
	else
		moveby1 = CCMoveBy::create(2, ccp(10, 0));
	//创建回调动作，巡逻路线完后
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monstershooter::StopAnimation));
	//创建连续动作
	CCActionInterval* xunluo = CCSequence::create(moveby1, callFunc, NULL);
	this->runAction(xunluo);
}
//启动监听
void Monstershooter::StartListen(CCNode* m_hero, CCNode* m_map)
{
	my_hero = m_hero;
	my_map = m_map;
	this->schedule(schedule_selector(Monstershooter::updateMonster), 3.0f);//每隔3秒计算距离
	this->scheduleUpdate();//英雄一旦进入可视范围，怪物追着英雄打
}
//监听函数,每隔3秒检测下
void Monstershooter::updateMonster(float delta)
{
	//得到两点x的距离,记得怪物的坐标要加上地图的
	float x = my_hero->getPositionX() - (this->getPositionX() + my_map->getPositionX());
	//得到两点y的距离，记得怪物的坐标要加上地图的
	float y = my_hero->getPositionY() - (this->getPositionY() + my_map->getPositionY());
	//先计算怪物和英雄的距离
	dis = sqrt(pow(x, 2) + pow(y, 2));
	if (dis >= 300)
	{
		if (!IsRunning)
			MonsterSeeRun();
	}
}
void Monstershooter::update(float delta)
{
	if (dis < 30)///当英雄在它的可视范围内，不断追着英雄
		FollowRun(my_hero, my_map);
}


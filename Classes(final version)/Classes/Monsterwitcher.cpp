#include "Monsterwitcher.h"
USING_NS_CC;
Monsterwitcher::Monsterwitcher(void)
{
	IsRunning = false;//没在放动画
	MonsterwitcherDirecton = TRUE;//向右运动
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
Monsterwitcher* Monsterwitcher::createWithFileName(const char* name)//重载create
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
	//设置怪物的血条 
	bloodView = new ProgressViewBlood();
	bloodView->setPosition(ccp(this->getPositionX(), this->getPositionY() + 50));//设置在怪物上头  
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
		animation->addSpriteFrameWithFileName(szName); //加载动画的帧  
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(-1); //动画循环
	//将动画包装成一个动作
	CCAnimate* act = CCAnimate::create(animation);
	m_MonsterwitcherSprite->runAction(act);
	IsRunning = true;

}
void  Monsterwitcher::StopAnimation()
{
	if (!IsRunning)
		return;
	m_MonsterwitcherSprite->stopAllActions();//当前精灵停止所有动画
	//恢复精灵原来的初始化贴图 
	this->removeChild(m_MonsterwitcherSprite, TRUE);//把原来的精灵删除掉
	m_MonsterwitcherSprite = CCSprite::create(Monster_name);//恢复精灵原来的贴图样子
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
		animation->addSpriteFrameWithFileName(szName); //加载动画的帧  
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1); //动画循环1次  
	//将动画包装成一个动作
	CCAnimate* act = CCAnimate::create(animation);
	//创建回调动作，攻击结束后调用AttackEnd()
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monsterwitcher::AttackEnd));
	//创建连续动作
	CCActionInterval* attackact = CCSequence::create(act, callFunc, NULL);
	m_MonsterwitcherSprite->runAction(attackact);
	IsAttack = true;

}
void Monsterwitcher::AttackEnd()
{
	//恢复精灵原来的初始化贴图 
	this->removeChild(m_MonsterwitcherSprite, TRUE);//把原来的精灵删除掉
	m_MonsterwitcherSprite = CCSprite::create(Monster_name);//恢复精灵原来的贴图样子
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

	this->removeChild(m_MonsterwitcherSprite, TRUE);//把原来的精灵删除掉
}


void Monsterwitcher::FollowRun(Sprite* m_hero, TMXTiledMap* m_map)
{
	//得到两点x的距离,记得怪物的坐标要加上地图的
	float x = m_hero->getPositionX() - (this->getPositionX() + m_map->getPositionX());
	//得到两点y的距离，记得怪物的坐标要加上地图的
	float y = m_hero->getPositionY() - (this->getPositionY() + m_map->getPositionY());

	//先计算怪物和英雄的距离
	dis = sqrt(pow(x, 2) + pow(y, 2));

	if (dis >= 300)//当怪物与英雄距离超过300
		return;
	if (dis <= 100)//在怪物攻击范围内，怪物停止移动
	{
		this->StopAnimation();//停止跑动
		JudegeAttack();//以一定的概率判断是是否出动攻击
		return;
	}

	if (x < -100)//判断怪物横坐标和英雄的距离
	{

		MonsterwitcherDirecton = true;
		m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//设置方向
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() - 1, this->getPositionY());//怪物向英雄移动
		this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//播放动画

	}
	else if (x > 100)
	{

		MonsterwitcherDirecton = false;
		m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//设置方向
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() + 1, this->getPositionY());
		this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//播放动画
	}
	else if (x <= 100)//怪物橫坐標和英雄相差在100以内时，开始移动怪物纵坐标
	{

		if (m_hero->getPositionY() > this->getPositionY())
		{
			m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//设置方向
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() + 1);
			this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//播放动画
		}
		else if (m_hero->getPositionY() < this->getPositionY())
		{
			m_MonsterwitcherSprite->setFlipX(MonsterwitcherDirecton);//设置方向
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() - 1);
			this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//播放动画
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
	this->SetAnimation("monster_run", 1, MonsterwitcherDirecton);//播放动画
	CCMoveBy* moveby1;
	if (MonsterwitcherDirecton == true)
		moveby1 = CCMoveBy::create(2, ccp(-10, 0));
	else
		moveby1 = CCMoveBy::create(2, ccp(10, 0));
	//创建回调动作，巡逻路线完后
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Monsterwitcher::StopAnimation));
	//创建连续动作
	CCActionInterval* xunluo = CCSequence::create(moveby1, callFunc, NULL);
	this->runAction(xunluo);
}
//启动监听
void Monsterwitcher::StartListen(Sprite* m_hero, TMXTiledMap* m_map)
{
	my_hero = m_hero;
	my_map = m_map;
	this->schedule(schedule_selector(Monsterwitcher::updateMonster), 3.0f);//每隔3秒计算距离
	this->scheduleUpdate();//英雄一旦进入可视范围，怪物追着英雄打
}
//监听函数,每隔3秒检测下
void Monsterwitcher::updateMonster(float delta)
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
void Monsterwitcher::update(float delta)
{
	if (dis < 300)///当英雄在它的可视范围内，不断追着英雄
		FollowRun(my_hero, my_map);
}


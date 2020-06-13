#include <map>
#include "EnemyManager.h"


bool CEnemyManager::init()
{
	bool bRet = false;
	do {
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		m_iEnemyCout = 0;
		m_pEnemyList = CCSpriteBatchNode::create("Image/Monsters.png");
		this->addChild(m_pEnemyList);
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Image/Monsters.plist");
		this->scheduleUpdate();
		/**	敌人出现管理	*/
		this->schedule(schedule_selector(CEnemyManager::createNewEnemys), 1.0f);


		this->scheduleOnce(schedule_selector(CEnemyManager::createBoss), 100.0f);
		bRet = true;
	} while (0);

	return bRet;
}

void CEnemyManager::addEnemy()
{
	int iTag = -1;
	CEnemySprite* pEnemy = (CEnemySprite*)CEnemySprite::create(rand() % 3 + 1);
	for (int i = 0; i < m_iEnemyCout; i++)
	{
		CCSprite* pSprite = (CCSprite*)m_pEnemyList->getChildByTag(i);
		if (!pSprite)
		{
			iTag = i;
			break;
		}
	}
	if (iTag == -1)
	{
		iTag = m_iEnemyCout;
		m_iEnemyCout++;
	}
	m_pEnemyList->addChild(pEnemy->getSprite(), 1, iTag);
	this->addChild(pEnemy, 1, iTag);
}

void CEnemyManager::createNewEnemys(float dt)
{
	addEnemy();
}

void CEnemyManager::createBoss(float dt)
{
	int iBossType = g_iGameLevel - 1;
	CBossSprite* pBoss = CBossSprite::create(iBossType);
	this->addChild(pBoss, 1, 100);
	this->unschedule(schedule_selector(CEnemyManager::createNewEnemys));
}


void CEnemyManager::update(float dt)
{
	CEnemySprite* pEnemy = NULL;
	for (int i = 0; i < m_iEnemyCout; i++)
	{
		pEnemy = (CEnemySprite*)this->getChildByTag(i);
		if (pEnemy && pEnemy->isDestroy() == true)
		{
			m_pEnemyList->removeChildByTag(i, true);
			this->removeChildByTag(i, true);
		}
	}
}

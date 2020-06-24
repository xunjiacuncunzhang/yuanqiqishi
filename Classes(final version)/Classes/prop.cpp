#include "prop.h"
#include"cocos2d.h"
#include"safemap.h"
#include"backpack.h"

USING_NS_CC;

prop* prop::createWithFileName(const char* name)//ÖØÔØcreate
{
	prop * props = new prop();
	if (props && props->initWithFile(name))
	{
		props->autorelease();
		return props;
	}
	CC_SAFE_DELETE(props);
	return NULL;

}

bool prop::init()
{
	return true;
}

void prop::setPropData(INT32 data)
{
	this->propData = data;
}

INT32 prop::getPropData()
{
	return this->propData;
}

void prop::useProp(Player* knight)
{
	float curMP = 0;
	switch (this->propData)
	{
	case 0:
		if (knight->bloodView->getCurrentProgress() >= knight->bloodView->getTotalProgress())
		{
			safemap::myBag.add(1, 0,knight);
		}
		else
		{
			float curHP = knight->getCurrentBlood();
			knight->setCurrentBlood(25 + curHP);
			knight->bloodView->setCurrentProgress(knight->bloodView->getCurrentProgress() + 25);
		}
		break;
	case 1:
		if (knight->exp->getCurrentProgress() >= knight->exp->getTotalProgress())
		{
			safemap::myBag.add(0, 1,knight);
		}
		else
		{
			float curMP = knight->exp->getCurrentProgress();
			knight->exp->setCurrentExp(25 + curMP);
			knight->exp->setCurrentProgress(knight->exp->getCurrentProgress() + 2.5);
			break;
		}
	}
}
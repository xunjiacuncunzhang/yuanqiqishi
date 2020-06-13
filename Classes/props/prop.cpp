#include "prop.h"
#include"cocos2d.h"

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
	switch (this->propData)
	{
	case 0:
		/*INT32 curMP = knight->getMP() + 20;
		if (curMP >= 200) curMP = 200;
		knight->setMP(curMP);
		knight->setMP(25 + (knight->getMP()));*/
		break;
	case 1:
		knight->setCurrentBlood(20 + (knight->getCurrentBlood()));
		break;
	}
}
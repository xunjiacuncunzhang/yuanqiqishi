#include "ControlAudioSlider.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

ControlAudioSlider::ControlAudioSlider()
{
}


ControlAudioSlider::~ControlAudioSlider()
{
}

ControlAudioSlider* ControlAudioSlider::create(const char* bgFile, const char* progressFile, const char* thumbFile)
{
	Sprite* backgroundSprite = Sprite::create(bgFile);
	Sprite* progressSprite = Sprite::create(progressFile);
	Sprite* thumbSprite = Sprite::create(thumbFile);

	ControlAudioSlider* pRet = new (std::nothrow) ControlAudioSlider();
	pRet->initWithSprites(backgroundSprite, progressSprite, thumbSprite);

	return pRet;
}

bool ControlAudioSlider::onTouchBegion(Touch* touch, Event* pEvent)
{
	bool b = extension::ControlSlider::onTouchBegan(touch, pEvent);
	return b;
}

void ControlAudioSlider::onTouchMoved(Touch* touch, Event* pEvent)
{
	extension::ControlSlider::onTouchMoved(touch, pEvent);
	_ratio = getValue() / getMaximumValue();
	if (_callback)
	{
		_callback(this, _ratio, pEvent);
	}
}

void ControlAudioSlider::setCallBack(const audioSliderCallback& callback)
{
	_callback = callback;
}

void ControlAudioSlider::setValues(float minValue, float maxValue, float value)
{
	this->setMinimumValue(minValue);
	this->setMaximumValue(maxValue);
	this->setValue(value);
}

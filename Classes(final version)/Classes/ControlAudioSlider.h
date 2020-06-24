#pragma once
#include "Cocos2d.h"
#include "extensions/GUI/CCControlExtension/CCControlSlider.h"

using namespace cocos2d;

class ControlAudioSlider :public extension::ControlSlider
{
public:
	ControlAudioSlider();
	~ControlAudioSlider();

	typedef std::function<void(ControlAudioSlider*, float, Event*)> audioSliderCallback;
	static ControlAudioSlider* create(const char* bgFile, const char* progressFile, const char* thumbFile);

	virtual bool onTouchBegion(Touch* touch, Event* pEvent);
	virtual void onTouchMoved(Touch* touch, Event* pEvent);

	void setValues(float minValue, float maxValue, float value);
	void setCallBack(const audioSliderCallback& callback);
private:
	audioSliderCallback	_callback;
	float _ratio;
};


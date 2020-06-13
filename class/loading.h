#ifndef _LOADING_H__  
#define _LOADING_H__  
#include "cocos2d.h"  
#include"ControlAudioSlider.h"
USING_NS_CC;
class Loading :cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void loadingLogic(float dt);
	void onEnter();
	void loadingCallback();
	CREATE_FUNC(Loading);

};
#endif
#ifndef __GamePause_H__
#define __GamePause_H__
#include"cocos2d.h"
USING_NS_CC;
class GamePause : public cocos2d::Layer
{
public:
	static cocos2d::Scene* scene(RenderTexture* sqr);//利用sqr纹理图创建场景wxl
	virtual bool init();
	void continueCallBack(Object* pSender);//回调函数
	CREATE_FUNC(GamePause);
};
#endif // !__GamePause_H__

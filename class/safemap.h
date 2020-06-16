#ifndef __SAFEMAP_H__
#define __SAFEMAP_H__
#include "cocos2d.h"
USING_NS_CC;
class JoyStick;
class safemap : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
   // implement the "static create()" method manually
    void back(Ref* pSender);
    void update(float dt);  
    void set(Ref* pSneder);
    void pause(Ref* pSender);
    void book(Ref* pSender);
    void bag(Ref* pSender);
    CREATE_FUNC(safemap);
private:
    JoyStick* rocker;
};
#endif // __HELLOWORLD_SCENE_H__



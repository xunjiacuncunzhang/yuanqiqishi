#ifndef __ProgressViewBlood__
#define __ProgressViewBlood__

#include "cocos2d.h"

USING_NS_CC;

class ProgressViewBlood : public CCNode
{
public:
    ProgressViewBlood();
    ~ProgressViewBlood();

public:
    //static ProgressViewBlood* createWithFileName(const char* name);//重载
    //设置血条背景
    void setBackgroundTexture(const char* pName);
    //设置血条前景
    void setForegroundTexture(const char* pName);
    //设置总血量
    void setTotalProgress(float total);
    //设置当前血量
    void setCurrentProgress(float progress);
    //得到当前血量
    float getCurrentProgress() ;
    //得到总血量
    float getTotalProgress() ;

private:

    //设置前景血条显示的长度
    void setForegroundTextureRect( CCRect& rect);

private:
    CCSprite* m_progressBackground;//背景血条
    CCSprite* m_progressForeground;//前景血条
    float m_totalProgress;//总血量
    float m_currentProgress;//当前血量
    float m_scale;//放大倍数  可删
};


#endif
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
    //static ProgressViewBlood* createWithFileName(const char* name);//����
    //����Ѫ������
    void setBackgroundTexture(const char* pName);
    //����Ѫ��ǰ��
    void setForegroundTexture(const char* pName);
    //������Ѫ��
    void setTotalProgress(float total);
    //���õ�ǰѪ��
    void setCurrentProgress(float progress);
    //�õ���ǰѪ��
    float getCurrentProgress() ;
    //�õ���Ѫ��
    float getTotalProgress() ;

private:

    //����ǰ��Ѫ����ʾ�ĳ���
    void setForegroundTextureRect( CCRect& rect);

private:
    CCSprite* m_progressBackground;//����Ѫ��
    CCSprite* m_progressForeground;//ǰ��Ѫ��
    float m_totalProgress;//��Ѫ��
    float m_currentProgress;//��ǰѪ��
    float m_scale;//�Ŵ���  ��ɾ
};


#endif
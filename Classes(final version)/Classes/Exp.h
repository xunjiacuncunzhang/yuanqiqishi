#pragma once


#ifndef __Exp__
#define __Exp__

#include "cocos2d.h"

USING_NS_CC;
class Exp : public CCNode
{
public:
	Exp();
	~Exp();

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
	float getCurrentProgress();
	//�õ���Ѫ��
	float getTotalProgress();

	void setCurrentExp(float getexp);//�������߼��� getexp�����ɸ�
private:

	//����ǰ��Ѫ����ʾ�ĳ���
	void setForegroundTextureRect(CCRect& rect);

private:
	CCSprite* ExpBackground;//����Ѫ��
	CCSprite* ExpForeground;//ǰ��Ѫ��
	float totalExp;//��Ѫ��
	float currentExp;//��ǰѪ��
	float m_scale;//�Ŵ���  ��ɾ
};


#endif


#include "ProgressViewBlood.h"

USING_NS_CC;


ProgressViewBlood::ProgressViewBlood(void) {
}

ProgressViewBlood::~ProgressViewBlood(void) {
}


void ProgressViewBlood::setBackgroundTexture(const char* pName)
{
    m_progressBackground = CCSprite::create(pName);
    m_progressBackground->setScale(0.1);
    m_progressBackground->setAnchorPoint(ccp(0.0f, 0.0f));
    this->addChild(m_progressBackground);
}

void ProgressViewBlood::setForegroundTexture(const char* pName)
{
    m_progressForeground = CCSprite::create(pName);
    m_progressForeground->setScale(0.1);
    m_progressForeground->setAnchorPoint(ccp(0.0f, 0.0f));//设置锚点
    //m_progressForeground->setPosition(ccp(-m_progressForeground->getContentSize().width * 0.5f, 0));
    this->addChild(m_progressForeground);
}
void ProgressViewBlood::setTotalProgress(float total)
{
    if (m_progressForeground == NULL) { return; }
    m_scale = m_progressForeground->getContentSize().width / total; // 放大倍数
    m_totalProgress = total;
}

void ProgressViewBlood::setCurrentProgress(float progress)
{
    if (m_progressForeground == NULL) { return; }
    if (progress < 0.0f) { progress = 0.0f; }
    if (progress > m_totalProgress) { progress = m_totalProgress; }
    m_currentProgress = progress;
    float rectWidth = progress * m_scale;//放大倍数
    //CCPoint from = m_progressForeground->getTextureRect().origin;
    CCRect rect = CCRectMake(0,0, rectWidth, m_progressForeground->getContentSize().height);
    setForegroundTextureRect(rect);
}

void ProgressViewBlood::setForegroundTextureRect( CCRect& rect)
{
    m_progressForeground->setTextureRect(rect);
}



float ProgressViewBlood::getCurrentProgress() 
{
    return m_currentProgress;
}

float ProgressViewBlood::getTotalProgress() 
{
    return m_totalProgress;
}



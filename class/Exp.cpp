#include "Exp.h"
USING_NS_CC;


USING_NS_CC;

Exp::Exp(void) {
}

Exp::~Exp(void) {
}


void Exp::setBackgroundTexture(const char* pName)
{
    ExpBackground = CCSprite::create(pName);
    ExpBackground->setScale(0.1);
    ExpBackground->setAnchorPoint(ccp(0.0f, 0.0f));
    this->addChild(ExpBackground);
}

void Exp::setForegroundTexture(const char* pName)
{
    ExpForeground = CCSprite::create(pName);
    ExpForeground->setScale(0.1);
    ExpForeground->setAnchorPoint(ccp(0.0f, 0.0f));//设置锚点
    ExpForeground->setPosition(ccp(150,550));
    this->addChild(ExpForeground);
}
void Exp::setTotalProgress(float total)
{
    if (ExpForeground == NULL) { return; }
    m_scale = ExpForeground->getContentSize().width / total; // 放大倍数
    totalExp = total;
}

void Exp::setCurrentProgress(float progress)
{
    if (ExpForeground == NULL) { return; }
    if (progress < 0.0f) { progress = 0.0f; }
    if (progress > totalExp) { progress = totalExp; }
    currentExp = progress;
    float rectWidth = progress * m_scale;//放大倍数
    //CCPoint from = m_progressForeground->getTextureRect().origin;
    CCRect rect = CCRectMake(0, 0, rectWidth, ExpForeground->getContentSize().height);
    setForegroundTextureRect(rect);
}

void Exp::setForegroundTextureRect(CCRect& rect)
{
    ExpForeground->setTextureRect(rect);
}

void Exp::setCurrentExp(float getexp) {
    this->currentExp = this->currentExp + getexp;
    if (this->currentExp > 100)this->currentExp = 100;
}

float Exp::getCurrentProgress()
{
    return currentExp;
}

float Exp::getTotalProgress()
{
    return totalExp;
}


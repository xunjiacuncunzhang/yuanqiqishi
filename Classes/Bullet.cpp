#include "Bullet.h"
#include"Player.h"
#include"weapon.h"
USING_NS_CC;

Bullet::Bullet() {

}

Bullet::~Bullet() {
    m_allBulletArray->release();
}

void Bullet::init(Point pointPlayer) {
    winSize = CCDirector::sharedDirector()->getWinSize();

    //�����������飬�����Ѵ��ڵ��ӵ�
    m_allBulletArray = CCArray::create();
    m_allBulletArray->retain();

    //�ӵ���ͼ
    m_bulletSprite = CCSpriteBatchNode::create("bullet1.png");
    //m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
    addChild(m_bulletSprite);

}

//����һ�����ӵ�
void Bullet::addNewBullet(weapon *weapon) {//������оͻ�������
    //����һ���ӵ�����ӵ�BatchNode�С�
    CCSprite* newBullet = CCSprite::createWithTexture(m_bulletSprite->getTexture());
    Point pointWeapon = weapon->getPosition();
    newBullet->setPosition(ccp(pointWeapon.x + 10, pointWeapon.y));
    m_bulletSprite->addChild(newBullet);

    //����ӵ����Ѵ����ӵ�����
    m_allBulletArray->addObject(newBullet);
}

//�ƶ��ӵ� 
void Bullet::moveBullet(Player* player, Monster *monster) {//�����õ���ͬѧ�Ĺ�����
    //��������ÿ���ӵ���λ��
    for (int i = 0; i < m_allBulletArray->count(); ++i) {
        //��ȡһ���ӵ�����
        CCSprite* bullet = (CCSprite*)m_allBulletArray->objectAtIndex(i);
        auto posMonster = monster->getPosition();//��ȡ����λ��
        //����λ��
        CCActionInterval* moveTo = CCMoveTo::create(0.5f,ccp(posMonster.x, posMonster.y));//�����λ��
        bullet->runAction(moveTo);
        //����ѵ�����ʧλ�ã����Ƴ����ӵ�

        CCRect cr1 = player->boundingBox();
        CCRect cr2 = monster->boundingBox();//��ȡ������ӵ�

        if (cr1.intersectsRect(cr2))	//�Ƿ���ڽ���
        {
            //�ӵ��������� ��ʧ
            m_allBulletArray->removeObjectAtIndex(i);
            m_bulletSprite->removeChild(bullet, true);
            log("monster attacked");
            //������ʹ�����Ѫ
        }
        Point pointBullet = bullet->getPosition;
        if(pointBullet.x>500||pointBullet.y>500){//�ɳ����� ���ݻ����С�ٸ�
            m_allBulletArray->removeObjectAtIndex(i);
            m_bulletSprite->removeChild(bullet, true);
            log("no");
        }
           
        if (monster->getCurrentBlood() == 0) {
            monster->died();//�����������
        }
    }
}
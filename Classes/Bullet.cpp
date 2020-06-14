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

    //创建对象数组，保存已存在的子弹
    m_allBulletArray = CCArray::create();
    m_allBulletArray->retain();

    //子弹贴图
    m_bulletSprite = CCSpriteBatchNode::create("bullet1.png");
    //m_bulletSprite->setPosition(ccp(pointPlayer.x + 20, pointPlayer.y - 10));
    addChild(m_bulletSprite);

}

//增加一个新子弹
void Bullet::addNewBullet(weapon *weapon) {//如果不行就换成坐标
    //构建一个子弹，添加到BatchNode中。
    CCSprite* newBullet = CCSprite::createWithTexture(m_bulletSprite->getTexture());
    Point pointWeapon = weapon->getPosition();
    newBullet->setPosition(ccp(pointWeapon.x + 10, pointWeapon.y));
    m_bulletSprite->addChild(newBullet);

    //添加子弹到已存在子弹数组
    m_allBulletArray->addObject(newBullet);
}

//移动子弹 
void Bullet::moveBullet(Player* player, Monster *monster) {//这里用到许同学的怪物类
    //遍历更新每个子弹的位置
    for (int i = 0; i < m_allBulletArray->count(); ++i) {
        //获取一个子弹对象
        CCSprite* bullet = (CCSprite*)m_allBulletArray->objectAtIndex(i);
        auto posMonster = monster->getPosition();//获取怪物位置
        //更新位置
        CCActionInterval* moveTo = CCMoveTo::create(0.5f,ccp(posMonster.x, posMonster.y));//怪物的位置
        bullet->runAction(moveTo);
        //如果已到达消失位置，就移除该子弹

        CCRect cr1 = player->boundingBox();
        CCRect cr2 = monster->boundingBox();//获取怪物的子弹

        if (cr1.intersectsRect(cr2))	//是否存在交集
        {
            //子弹碰到怪物 消失
            m_allBulletArray->removeObjectAtIndex(i);
            m_bulletSprite->removeChild(bullet, true);
            log("monster attacked");
            //在这里使怪物掉血
        }
        Point pointBullet = bullet->getPosition;
        if(pointBullet.x>500||pointBullet.y>500){//飞出画面 根据画面大小再改
            m_allBulletArray->removeObjectAtIndex(i);
            m_bulletSprite->removeChild(bullet, true);
            log("no");
        }
           
        if (monster->getCurrentBlood() == 0) {
            monster->died();//如果怪物死亡
        }
    }
}
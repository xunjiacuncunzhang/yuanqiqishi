#include "weapon.h"
#include"Bullet.h"
#include"Player.h"
USING_NS_CC;

weapon::weapon(void) {
}

weapon::~weapon(void) {
}

weapon* weapon::createWithFileName(char* name)//����create
{
	weapon* pweapon = new weapon();
	if (pweapon && pweapon->initWithFile(name))
	{
		pweapon->autorelease();
		return pweapon;
	}
	CC_SAFE_DELETE(pweapon);
	return NULL;

}

void weapon::InitweaponSprite() {
	bullet -> Bullet::create();
	addChild(bullet);
}
void weapon::controlBullet(Player* qishi, Monster* monster) {
	bullet->addNewBullet(this);//������оͻ�������
	bullet->moveBullet(qishi, monster);
}
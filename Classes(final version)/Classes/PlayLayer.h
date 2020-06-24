#pragma once
#ifndef PLAYLAYER_H_
#define PLAYLAYER_H_
#include "cocos2d.h"
#include"keyBoardDelegate.h"
#include"KeyboardControl.h"
#include"Player.h"
#include"ProgressViewBlood.h"
#include"prop.h"
#include"PlayScene.h"
#include"weapon.h"
#include"Monsterwitcher.h"
#include"Monstershooter.h"
#include"Monster.h"
#include"Monsterwitcherboss.h"
#include"Bullet.h"
#include"Entity.h"
#include"Enemybossbullet.h"
#include"Enemyshooterbullet.h"
#include"Enemywitcherbullet.h"

USING_NS_CC;
class Player;
class PlayScene;

class playLayer :public cocos2d::Layer, public keyBoardDelegate
{
public:
	virtual bool init();

	void initMap();
	void initHero();
	void initBattleRoom();
	void initNextLevelRoom();
	/*void initMonsterwitcher();*/

	//���ɹ���
	void initMonster1();
	void initMonster2();
	void initMonster3();
	void initMonster4();
	void initMonster5();
	void initMonster6();
	void initMonster7();
	void initMonster8();
	void initMonster9();
	void initMonster10();
	void initMonster11();
	void initMonster12();
	void initMonster13();
	void initMonster14();
	void initMonster15();
	void initMonster16();
	void initMonster17();
	void initMonster18();



	//���﹥��
	void EnemymakeAttackation1(float delta);
	void EnemymakeAttackation2(float delta);


	//���º������ڽ�ɫ�ƶ�����
	Point tileToWin(Point position);
	Point winToTile(Point position);
	bool isTileBlocked(Point position);
	void setViewPointCenter(cocos2d::Point position);
	void update(float delta) override;
	void updatePosition();

	//�̳���keyBoardDelegate����������
	virtual void didChangeDirectionTo(cocos2d::CCPoint direction);
	virtual void isHoldingDirection(cocos2d::CCPoint direction);

	//���º���������Ϸ��ͣ
	void menuPauseCallback(Ref* pSender);

	//���ý���
	void menuSetCallback(Ref* pSender);

	//��ȡ����
	void getProps(Ref* pSender);
	void getWeapon(Ref* pSender);
	Vector<weapon*>& getWeaponVec();
	void changeWeapon();
	void bag(Ref* pSender);

	//��ʼ����
	void makeAttackation(float delta);

	//��һ��
	void nextLevel(Ref* pSender);

	CC_SYNTHESIZE(KeyboardControl*, _control, Control);
	CREATE_FUNC(playLayer);


private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keySituation;
	//��ͼ���
	TMXTiledMap *map = NULL;
	TMXLayer *block = NULL;
	Point _direction;
	INT32 mapType = 0;

	//��������Ѫ��
	Player *knight = NULL;
	ProgressViewBlood* bloodView = NULL;
	Monsterwitcher* monster1;
	Monstershooter* monster2;
	Monster* monster3;
	Monster* monster4;
	Monsterwitcher* monster5;
	Monstershooter* monster6;
	Monsterwitcherboss* monster7;
	Monstershooter* monster8;
	Monstershooter* monster9;
	Monsterwitcher* monster10;
	Monster * monster11;
	Monstershooter* monster12;
	Monsterwitcher* monster13;
	Monsterwitcherboss* monster14;
	Monsterwitcherboss* monster15;
	Monsterwitcherboss* monster16;
	Monstershooter* monster17;
	Monsterwitcher* monster18;




	//��ť���
	CCMenu *pMenu1 = NULL;
	CCMenu *pMenu2 = NULL;
	CCMenu *m_bag = NULL;

	//����
	CCMenu *pboxMenu1 = NULL;
	CCMenu *pboxMenu2 = NULL;
	CCMenu *pboxMenu3 = NULL;
	prop *props = NULL;
	int boxNum = 0;

	//����
	Vector<weapon*> vecWeapon;
	weapon* currentWeapon;
	Bullet* bullet;

	//��������
	Enemyshooterbullet* shooterbullet2;
	Enemyshooterbullet* shooterbullet6;
	Enemyshooterbullet* shooterbullet8;
	Enemyshooterbullet* shooterbullet9;
	Enemyshooterbullet* shooterbullet12;
	Enemyshooterbullet* shooterbullet17;

	Enemybossbullet* bossbullet7U;
	Enemybossbullet* bossbullet7R;
	Enemybossbullet* bossbullet7D;
	Enemybossbullet* bossbullet7L;

	Enemybossbullet* bossbullet14U;
	Enemybossbullet* bossbullet14R;
	Enemybossbullet* bossbullet14D;
	Enemybossbullet* bossbullet14L;

	Enemybossbullet* bossbullet15U;
	Enemybossbullet* bossbullet15R;
	Enemybossbullet* bossbullet15D;
	Enemybossbullet* bossbullet15L;

	Enemybossbullet* bossbullet16U;
	Enemybossbullet* bossbullet16R;
	Enemybossbullet* bossbullet16D;
	Enemybossbullet* bossbullet16L;

	Enemywitcherbullet* witcherbullet1U;
	Enemywitcherbullet* witcherbullet1R;
	Enemywitcherbullet* witcherbullet1D;
	Enemywitcherbullet* witcherbullet1L;

	Enemywitcherbullet* witcherbullet5U;
	Enemywitcherbullet* witcherbullet5R;
	Enemywitcherbullet* witcherbullet5D;
	Enemywitcherbullet* witcherbullet5L;

	Enemywitcherbullet* witcherbullet10U;
	Enemywitcherbullet* witcherbullet10R;
	Enemywitcherbullet* witcherbullet10D;
	Enemywitcherbullet* witcherbullet10L;

	Enemywitcherbullet* witcherbullet13U;
	Enemywitcherbullet* witcherbullet13R;
	Enemywitcherbullet* witcherbullet13D;
	Enemywitcherbullet* witcherbullet13L;

	Enemywitcherbullet* witcherbullet18U;
	Enemywitcherbullet* witcherbullet18R;
	Enemywitcherbullet* witcherbullet18D;
	Enemywitcherbullet* witcherbullet18L;
	Vector<Entity*> vecMonster;
	Vector<Entity*> vecplayer;
};
#endif


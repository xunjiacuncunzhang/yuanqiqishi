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

USING_NS_CC;
class Player;
class PlayScene;

class playLayer:public cocos2d::Layer,public keyBoardDelegate
{
public:
	virtual bool init();
	
	void initMap();
	void initHero();
	void initBattleRoom();
	void initNextLevelRoom();
	void initBloodProgress();


	//以下函数用于角色移动辅助
	Point tileToWin(Point position);
	Point winToTile(Point position);
	bool isTileBlocked(Point position);
    void setViewPointCenter(cocos2d::Point position);
	void update(float delta) override;
	void updatePosition();
	
	//继承于keyBoardDelegate的两个函数
	virtual void didChangeDirectionTo(cocos2d::CCPoint direction);
	virtual void isHoldingDirection(cocos2d::CCPoint direction);
	
	//以下函数用于游戏暂停
	void menuPauseCallback(Ref* pSender);

	//设置界面
	void menuSetCallback(Ref* pSender);

	//获取宝箱
	void getProps(Ref* pSender);

	//下一关
	void nextLevel(Ref* pSender);

	CC_SYNTHESIZE(KeyboardControl*, _control, Control);
	CREATE_FUNC(playLayer);


private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keySituation;
	//地图相关
	TMXTiledMap *map=NULL;
	TMXLayer *block=NULL;
	Point _direction;
	
	//人物和血条
	Player *knight = NULL;
	ProgressViewBlood* bloodView;

	//按钮相关
	CCMenu *pMenu1 = NULL;
	CCMenu *pMenu2 = NULL;

	//宝箱
	CCMenu *pboxMenu1 = NULL;
	CCMenu *pboxMenu2 = NULL;
	prop *props = NULL;
};
#endif


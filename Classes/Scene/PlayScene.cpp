#include "PlayScene.h"
#include"KeyboardControl.h"
#include"Player.h"
#include"cocos2d.h"
#include"keyBoardDelegate.h"
#include"PlayLayer.h"

USING_NS_CC;

PlayScene::PlayScene()
{
	_playLayer = NULL;
	_controlLayer = NULL;
}

bool PlayScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		_playLayer = playLayer::create();
		this->addChild(_playLayer, 0);
		_controlLayer = KeyboardControl::create();
		this->addChild(_controlLayer, 1);

		_controlLayer->setDelegate(_playLayer);
		_playLayer->setControl(_controlLayer);

		bRet = true;
	} while (0);

	return bRet;
}

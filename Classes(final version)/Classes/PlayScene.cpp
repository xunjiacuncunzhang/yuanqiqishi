#include "PlayScene.h"
#include"KeyboardControl.h"
#include"Player.h"
#include"cocos2d.h"
#include"keyBoardDelegate.h"
#include"PlayLayer.h"
#include"MyScene.h"

USING_NS_CC;
INT32 PlayScene::level;

PlayScene::PlayScene()
{
	_playLayer = NULL;
	_controlLayer = NULL;
}

bool PlayScene::init()
{
	level++;
	CCLOG("level:%d", level);
	bool bRet = false;

	if (level > 3)
	{
		auto size = Director::getInstance()->getVisibleSize();
		CCMenuItemFont::setFontSize(32);    //�����ֺ�  
		CCMenuItemFont::setFontName("Marker Felt"); //��������  
		CCMenuItemFont *font1 = CCMenuItemFont::create("You Win! click here to restart", this, menu_selector(PlayScene::reStart));//������ְ�ť�����ʵ������  
		font1->setColor(ccc3(255, 0, 0));  //������ɫ  

		CCMenu *newmenu = CCMenu::create(font1,NULL); 
		newmenu->setPosition(ccp(size.width / 2, size.height / 2));
		newmenu->alignItemsVertically();     //����Ϊ��������  
		this->addChild(newmenu, 2);

		return true;
	}
	else
	{
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
}


void PlayScene::reStart(Ref*pesender)
{
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5f, MyWorld::createScene()));
}
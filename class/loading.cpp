#include "Loading.h"
#include "safemap.h"
#include"ControlAudioSlider.h"
#include"ui/CocosGUI.h"

USING_NS_CC;
int _curProgress;
ControlAudioSlider* _progressBar;
Sprite* _barTip;
LabelTTF* _barTipLabel;
Scene* Loading::createScene()
{
	auto scene = Scene::create();
	auto layer = Loading::create();
	scene->addChild(layer);
	return scene;
}
bool Loading::init()
{
	auto winSize = Director::getInstance()->getWinSize();
	auto background = Sprite::create("background.jpg");
	background->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(background, 0);
	auto _loadingLabel = LabelTTF::create("Loading...", "Arial", 25);
	_loadingLabel->setPosition(winSize.width / 2, winSize.height / 2 - 50);
	this->addChild(_loadingLabel);
	//标签
	 _curProgress = 0;
	 _progressBar = ControlAudioSlider::create("sliderTrack.png", "sliderProgress.png", "sliderThumb.png");
	_progressBar->setPosition(winSize.width / 2, winSize.height / 2);
	_progressBar->setTouchEnabled(false);
	_progressBar->setMinimumValue(0);
	_progressBar->setMaximumValue(100);
	_progressBar->setValue(0);
	this->addChild(_progressBar, 1);

	 _barTip=Sprite::create("tip.png");
	_barTip->setPosition(
		winSize.width / 2 - _progressBar->getContentSize().width / 2,
		winSize.height / 2 + 50);
	this->addChild(_barTip, 1);
	 _barTipLabel = LabelTTF::create("0%", "Arial", 20);
	_barTipLabel->setPosition(
		_barTip->getContentSize().width / 2, _barTip->getContentSize().height / 2
	);

	_barTip->addChild(_barTipLabel);
	this->schedule(schedule_selector(Loading::loadingLogic), 1.0 / 100, 100, 0.2f);
		
	return true;
}
void Loading::loadingLogic(float dt) 
{
	_curProgress++;
	if (_curProgress >=7) 
	{
		//begin the game choose scene
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, safemap::createScene()));
		return;
	}
	_progressBar->setValue(_curProgress);

	int startX = _progressBar->getPositionX() - _progressBar->getContentSize().width / 2 + 10;
	int unitX = _progressBar->getContentSize().width / 100;

	_barTip->setPositionX(startX + _curProgress * unitX);
		char str[10] = { 0 };
		sprintf(str, "%d", _curProgress);

	_barTipLabel->setString(str);

	}

void Loading::loadingCallback() {
	_curProgress++;
	if (_curProgress >=7 ) 
	{
		//begin the game choose scene
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, safemap::createScene()));
		return;
	}
	_progressBar->setValue(_curProgress);

	int startX = _progressBar->getPositionX() - _progressBar->getContentSize().width / 2 + 10;
	int unitX = _progressBar->getContentSize().width / 100;

	_barTip->setPositionX(startX + _curProgress * unitX);
	char str[10] = { 0 };
	sprintf(str, "%d%", _curProgress);

	_barTipLabel->setString(str);

}

void Loading::onEnter() {
	Layer::onEnter();
	//加载一次图片资源就回调一次
	Director::getInstance()->getTextureCache()->addImageAsync("joystick.png", callfunc_selector(Loading::loadingCallback));
	Director::getInstance()->getTextureCache()->addImageAsync("joystickBG.png", callfunc_selector(Loading::loadingCallback));
	Director::getInstance()->getTextureCache()->addImageAsync("knight.png", callfunc_selector(Loading::loadingCallback));
	Director::getInstance()->getTextureCache()->addImageAsync("backbutton.png", callfunc_selector(Loading::loadingCallback));
	Director::getInstance()->getTextureCache()->addImageAsync("backbuttonselected.png", callfunc_selector(Loading::loadingCallback));
	Director::getInstance()->getTextureCache()->addImageAsync("set.png", callfunc_selector(Loading::loadingCallback));
	Director::getInstance()->getTextureCache()->addImageAsync("setselected.png", callfunc_selector(Loading::loadingCallback));
}
#include "SetScene.h"
#include"SimpleAudioEngine.h"
#include"ui/CocosGUI.h"
#include"gamePause.h"
#include"ControlAudioSlider.h"
#include"string.h"


USING_NS_CC;

Scene* SetWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = SetWorld::create();
	scene->addChild(layer);
	return scene;
}
bool SetWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("backgroundmusic.mp3", true);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto labhead = Label::createWithSystemFont("Option", "Arial", 60);

	labhead->setTextColor(Color4B::WHITE);

	labhead->setPosition(Point(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2 + 250));

	this->addChild(labhead, 1);

	auto* pButton1 = MenuItemImage::create("backbutton.jpg", "backbuttonselected.jpg", this, menu_selector(SetWorld::back));
	auto* button1 = Menu::create(pButton1, NULL, NULL);
	button1->setAnchorPoint(Vec2(0, 0));
	button1->setPosition(visibleSize.width * 5 / 6, visibleSize.height * 5 / 6);
	button1->setScale(0.05f);
	addChild(button1, 1);
	auto* background = Sprite::create("background.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(0.9f);
	this->addChild(background);//ÉèÖÃ±³¾°
	auto music_text = Text::create("Music", "Arial", 32);
	music_text->setPosition(Vec2(visibleSize.width * 0.25, visibleSize.height * 0.6));
	this->addChild(music_text);
	
	auto music_slider = Slider::create();
	music_slider->loadBarTexture("sliderTrack.png");
	music_slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
	music_slider->loadProgressBarTexture("sliderProgress.png");
	float musicPercent = UserDefault::getInstance()->getFloatForKey("musicPercent");
	//if (musicPercent == 0.0f)
	//{
		//musicPercent = 100.0f;
	//}
	music_slider->setPercent(musicPercent);
	music_slider->cocos2d::Node::setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.6));
	music_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED) {
			int percent = music_slider->getPercent();
			CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(float(percent) / 100);
			UserDefault::getInstance()->setFloatForKey("musicPercent", percent);
		}
		});
	this->addChild(music_slider);//ÊÂ¼þ¼àÌýÆ÷
	auto sound_text = Text::create("Sound", "Arial", 32);
	sound_text->setPosition(Vec2(visibleSize.width * 0.25, visibleSize.height * 0.35));
	this->addChild(sound_text);
	//wenben
	auto effects_slider = Slider::create();
	effects_slider->loadBarTexture("sliderTrack.png");
	effects_slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
	effects_slider->loadProgressBarTexture("sliderProgress.png");
	float effectPercent = UserDefault::getInstance()->getFloatForKey("effectPercent");
	//if (effectPercent == 0.0f)
	//{
		//effectPercent = 100.0f;
	//}
	effects_slider->setPercent(effectPercent);
	effects_slider->cocos2d::Node::setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.35));
	effects_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED) {
			int percent = effects_slider->getPercent();
			CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(float(percent) / 100);
			UserDefault::getInstance()->setFloatForKey("effectPercent", percent);
		}
		});
	this->addChild(effects_slider);
}
void SetWorld::back(cocos2d::Ref* pSender)
{
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("backgroundmusic.mp3");
	Director::getInstance()->popScene();
}
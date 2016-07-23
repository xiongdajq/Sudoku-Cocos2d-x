#include "coder.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* coder::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = coder::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool coder::init() {
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bgi = Sprite::create("coderl.png");
	bgi->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(bgi, 0);

	auto back_image = MenuItemImage::create("back.png", "back.png", CC_CALLBACK_1(coder::back, this));
	back_image->setPosition(Vec2(origin.x + visibleSize.width / 8 * 7, origin.y + visibleSize.height / 4));

	auto back_item = Menu::create(back_image, NULL);
	back_item->setPosition(Vec2(origin.x, origin.y));
	this->addChild(back_item, 100);


}

void coder::back(cocos2d::Ref* pSender) {
	Director::getInstance()->popScene();
}

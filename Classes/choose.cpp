#include "choose.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* Choose::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Choose::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool Choose::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto easyImage = MenuItemImage::create("easy.png", "easy.png", CC_CALLBACK_1(Choose::enter, this));
	auto easyItem = Menu::create(easyImage, NULL);
	easyItem->setPosition(Vec2(origin.x + visibileSize.width / 4, origin.y + visibileSize.height / 2));
	this->addChild(easyItem, 1);

	auto middleImage = MenuItemImage::create("middle.png", "middle.png", CC_CALLBACK_1(Choose::enter, this));
	auto middleItem = Menu::create(middleImage, NULL);
	middleItem->setPosition(Vec2(origin.x + visibileSize.width / 2, origin.y + visibileSize.height / 2));
	this->addChild(middleItem, 1);

	auto confuseImage = MenuItemImage::create("confuse.png", "confuse.png", CC_CALLBACK_1(Choose::enter, this));
	auto confuseItem = Menu::create(confuseImage, NULL);
	confuseItem->setPosition(Vec2(origin.x + visibileSize.width * 3/ 4, origin.y + visibileSize.height / 2));
	this->addChild(confuseItem, 1);
}

void Choose::enter(cocos2d::Ref* pSender) {
	Scene* game = GameScene::createScene();
	Director::getInstance()->pushScene(game);
}
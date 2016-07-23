#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene() {
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			Sprite* img = Sprite::create("image.png");
			Label* la = Label::create();

			img->setPosition(Vec2(origin.x + visibleSize.width / 4 + i * 38, origin.y + visibleSize.height / 4 - j * 38));
			la->setPosition(img->getPosition());
			
			this->addChild(img, 1);
			this->addChild(img, 2);
			la->setScale(0.5);
			la->setColor(Color3B::BLUE);
			labels* labels_ = new labels();
			labels_->image = img;
			labels_->col = j;
			labels_->row = i;
			labels_->label = la;
			map.pushBack(labels_);
		}
	}

	return true;
}
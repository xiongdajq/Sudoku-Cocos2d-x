#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <vector>
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
	auto img = Sprite::create();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (((i < 3 || i > 5) && (j < 3 || j > 5)) || (i > 2 && i < 6 && j > 2 && j < 6)) {
				img = Sprite::create("image.png");
			}
			else {
				img = Sprite::create("image1.png");
			}
			auto la = Label::createWithTTF("2", "fonts/Marker Felt.ttf", 24);

			img->setPosition(Vec2(origin.x + visibleSize.width / 4 + i * 38, origin.y + visibleSize.height * 3 / 4 - j * 38));
			la->setPosition(img->getPosition());
			
			this->addChild(img, 1);
			this->addChild(la, 2);
			la->setColor(Color3B::BLUE);
			labels labels_ = labels();
			labels_.image = img;
			labels_.col = j;
			labels_.row = i;
			labels_.label = la;
			map.push_back(labels_);
		}
	}

	for (int i = 0; i < 10; i++) {
		Button* btn = Button::create();
		btn->setScale(2.5);
		btn->setTitleText(to_string(i));
		this->addChild(btn, 1);
		btn->setPosition(Vec2(origin.x + visibleSize.width / 4 + i * 38, origin.y + visibleSize.height / 8));
		btn->addClickEventListener(CC_CALLBACK_2(GameScene::buttonEvent, this));
	}
	Button* clear = Button::create();
	clear->setScale(2.5);
	clear->setTitleText("C");
	clear->setPosition(Vec2(origin.x + visibleSize.width / 4 + 380, origin.y + visibleSize.height / 8));
	this->addChild(clear, 1);
	schedule(schedule_selector(GameScene::update), 0.1f, kRepeatForever, 0);
	addClickListener();
	return true;
}

void GameScene::buttonEvent(Ref * pSender, ui::Widget::TouchEventType type)
{
	ui::Button* button = dynamic_cast<ui::Button*>(pSender);
	string a = button->getTitleText();
	if (type == ui::Widget::TouchEventType::ENDED) {
		//todos
	}
}

void GameScene::update(float f)
{
	//todos
}

void GameScene::addClickListener()
{
	//todos
	auto dispather = Director::getInstance()->getEventDispatcher();
	auto eventListenerMouse = EventListenerMouse::create();
	eventListenerMouse->onMouseDown = CC_CALLBACK_2(GameScene::onMouseDown, this);
}

void GameScene::onMouseDown(Touch * touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());

}


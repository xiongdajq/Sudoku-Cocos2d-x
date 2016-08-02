#pragma once
#include "cocos2d.h"
#include <vector>
#include <ui\UIButton.h>
using namespace std;
using namespace cocos2d::ui;
USING_NS_CC;
class GameScene : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameScene);
    static cocos2d::Scene* createScene();
	virtual bool init();
	void buttonEvent(Ref *pSender, Widget::TouchEventType type);
	void update(float f);
	void addClickListener();
	void onMouseDown(Event* ev1);
private:
	typedef struct node
	{
		int row;
		int col;
		int num;
		bool canChange;
		cocos2d::Sprite* image;
		cocos2d::Label* label;
	}labels;
	labels current;
	std::vector<labels> map;
	cocos2d::Vector<Button*> button;
};


#pragma once
#include "cocos2d.h"
class GameScene : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameScene);
    static cocos2d::Scene* createScene();
	virtual bool init();
private:
	typedef struct node
	{
		int row;
		int col;
		int num;
		Sprite* image;
		Label* label;
	}labels;
	cocos2d::Vector<labels*> map;
};


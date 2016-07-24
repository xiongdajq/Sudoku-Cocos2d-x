#pragma once
#include "cocos2d.h"

using namespace std;
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
		cocos2d::Sprite* image;
		cocos2d::Label* label;
	}labels;
	std::vector<labels> map;
};


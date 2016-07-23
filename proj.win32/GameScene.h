#pragma once
#include "cocos2d.h"
class GameScene : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameScene);
    static cocos2d::Scene* createScene();
	virtual bool init();
};


#pragma once
#include "cocos2d.h"

class instruction : public cocos2d::Layer
{
public:
	CREATE_FUNC(instruction);
	static cocos2d::Scene* createScene();
	virtual bool init();
	void back(cocos2d::Ref* pSender);
};


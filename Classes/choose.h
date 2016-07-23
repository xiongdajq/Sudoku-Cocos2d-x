#pragma once
#include "cocos2d.h"

class Choose : public cocos2d::Layer
{
public:
	CREATE_FUNC(Choose);
	static cocos2d::Scene* createScene();
	virtual bool init();
	void back(cocos2d::Ref* pSender);
	void enter(cocos2d::Ref* pSender);
};


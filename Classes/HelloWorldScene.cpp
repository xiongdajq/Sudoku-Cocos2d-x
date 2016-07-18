#include "HelloWorldScene.h"
#include "instruction.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create("buttons/button_end.png",
										   "buttbutton_end_click.png",
		CC_CALLBACK_1(HelloWorld::quickGame, this));
	auto menu_quick = Menu::create(closeItem, NULL);
	menu_quick->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 2 / 8));
	this->addChild(menu_quick, 1);

	auto startItem = MenuItemImage::create("buttons/button_start.png",
		"buttbutton_start_click.png",
		CC_CALLBACK_1(HelloWorld::quickGame, this));
	auto menu_start = Menu::create(startItem, NULL);
	menu_start->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 5 / 8));
	this->addChild(menu_start, 1);

	auto instruction = MenuItemImage::create("buttons/button_instruction.png",
		"buttbutton_instruction_click.png",
		CC_CALLBACK_1(HelloWorld::intro, this));
	auto menu_instruction = Menu::create(instruction, NULL);
	menu_instruction->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 4 / 8));
	this->addChild(menu_instruction, 1);

	auto coder = MenuItemImage::create("buttons/button_coder.png",
		"buttbutton_coder_click.png",
		CC_CALLBACK_1(HelloWorld::quickGame, this));
	auto menu_coder = Menu::create(coder, NULL);
	menu_coder->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 3 / 8));
	this->addChild(menu_coder, 1);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    //////////////////////////////
    // 1. super init first
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

    return true;
}

void HelloWorld::quickGame(cocos2d::Ref* pSender) {
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::intro(cocos2d::Ref* pSender) {
	Scene* introduct = instruction::createScene();
	Director::getInstance()->pushScene(introduct);
}

#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
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
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	// 设置背景
	//0153F5
	LayerColor *bg = LayerColor::create(Color4B(5,87,249, 255));
	//bg->setBackground
	this->addChild(bg);

	// 瓦片地图
	auto tileLayer = TileLayer::create();
	this->addChild(tileLayer);

	// 新图层(受重力)
	/*auto touchLayer = LayerTouchMove::create();
	scene->addChild(touchLayer);*/

	return true;
}

// 专门加载4×4的角色图
CCAnimate* loadAnimateWith16Grid(std::string filePath, Role::Direction direction){

	Animation* animation = Animation::create();
	animation->setRestoreOriginalFrame(true);
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage(filePath);
	auto size = texture->getContentSize();

	for(int j = 0;j<4;j++){
		animation->addSpriteFrameWithTexture(texture,CCRectMake(size.width/4*j,size.height/4*(int)direction,
			size.width/4,size.height/4));
	}
	animation->setDelayPerUnit(5.0f/16.0f);

	Animate* animate = Animate::create(animation);
	animate->setTag(0);

	/*ActionManager* actionManager = sprite->getActionManager();
	actionManager->addAction(animate,sprite,false);*/

	return animate;
}

void GameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

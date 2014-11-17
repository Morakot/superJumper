#include "LayerTouchMove.h"

USING_NS_CC;

// 创建画布
LayerTouchMove* LayerTouchMove::create()
{
	LayerTouchMove *ret = new LayerTouchMove();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}

// 初始/主画面
bool LayerTouchMove::init(){
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto dinosaur = Sprite::create("dragon.png");
	dinosaur->setPosition(visibleSize/2);
	auto body = PhysicsBody::createCircle(dinosaur->getContentSize().width/2,PHYSICSBODY_MATERIAL_DEFAULT);
	dinosaur->setPhysicsBody(body);
	this->addChild(dinosaur);

	auto moveby = MoveBy::create(5.0f,Vec2(100.0f,0));
	auto repeat = RepeatForever::create(moveby);
	auto speed = Speed::create(repeat, 5.0f);
	dinosaur->runAction(speed);

}
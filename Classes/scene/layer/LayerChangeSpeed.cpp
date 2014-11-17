#include "LayerChangeSpeed.h"

USING_NS_CC;
using gr::SpriteX;

// 创建画布
LayerChangeSpeed* LayerChangeSpeed::create()
{
	LayerChangeSpeed *ret = new LayerChangeSpeed();
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
bool LayerChangeSpeed::init(){
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto dinosaur = SpriteX::create("dragon.png");
	dinosaur->setPosition(100,100);
	/*auto body = PhysicsBody::createCircle(dinosaur->getContentSize().width/2,PHYSICSBODY_MATERIAL_DEFAULT);
	dinosaur->setPhysicsBody(body);*/
	this->addChild(dinosaur);

	auto acc1 = Accelerater::create(Vec2(10,10));
	auto acc2 = Accelerater::create(Vec2(10,10));
	dinosaur->setSpeed(Vec2(0,0));
	dinosaur->runAction(Spawn::create(acc1,acc2,nullptr));
}
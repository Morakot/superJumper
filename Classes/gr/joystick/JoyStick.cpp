#include "JoyStick.h"

void JoyStick::loadButtonsWithXml(std::string fileName){
	// read and parse the xml
}

JoyStick* JoyStick::create(){
	JoyStick *ret = new JoyStick();
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

void JoyStick::addButton(CCSprite* button){
	this->addChild(button);
	Size size = button->getContentSize();
	button->setPosition(size.width/2,size.height/2);

	// 事件
	void addListener(EventDispatcher* ,Node* ,Node* );
	addListener(_eventDispatcher,button,this->puppet);
}

void addListener(EventDispatcher* _eventDispatcher,Node* button,Node* puppet){
	// 创建一个事件监听器类型为 OneByOne 的单点触摸
	auto listener1 = EventListenerTouchOneByOne::create();
	// 设置是否吞没事件，在 onTouchBegan 方法返回 true 时吞没
	listener1->setSwallowTouches(true);

	// 使用 lambda 实现 onTouchBegan 事件回调函数
	listener1->onTouchBegan = [](Touch* touch, Event* event){

		// 获取事件所绑定的 target 
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// 获取当前点击点所在相对按钮的位置坐标
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// 点击范围判断检测
		if (rect.containsPoint(locationInNode))
		{
			auto label = LabelTTF::create("Oh My Smurf!", "Arial", 60);
			target->getParent()->addChild(label);
			Role* puppet = static_cast<Role*>(static_cast<JoyStick*>(target->getParent())->getPuppet());
			puppet->move(Role::Direction::RIGHT);

			return true;
		}
		return false;
	};

	// 触摸移动时触发
	listener1->onTouchMoved = [](Touch* touch, Event* event){
	};

	// 点击事件结束处理
	listener1->onTouchEnded = [=](Touch* touch, Event* event){
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, button);
}

void JoyStick::setPuppet(Node* puppet){
	this->puppet = puppet;
}

Node* JoyStick::getPuppet(){
	return this->puppet;
}
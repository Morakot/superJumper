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

	// �¼�
	void addListener(EventDispatcher* ,Node* ,Node* );
	addListener(_eventDispatcher,button,this->puppet);
}

void addListener(EventDispatcher* _eventDispatcher,Node* button,Node* puppet){
	// ����һ���¼�����������Ϊ OneByOne �ĵ��㴥��
	auto listener1 = EventListenerTouchOneByOne::create();
	// �����Ƿ���û�¼����� onTouchBegan �������� true ʱ��û
	listener1->setSwallowTouches(true);

	// ʹ�� lambda ʵ�� onTouchBegan �¼��ص�����
	listener1->onTouchBegan = [](Touch* touch, Event* event){

		// ��ȡ�¼����󶨵� target 
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		// ��ȡ��ǰ�����������԰�ť��λ������
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		// �����Χ�жϼ��
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

	// �����ƶ�ʱ����
	listener1->onTouchMoved = [](Touch* touch, Event* event){
	};

	// ����¼���������
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
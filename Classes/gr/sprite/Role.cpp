#include "Role.h"
#include<new>
#include<stdio.h>
#include "../graphicrazy.h"

// �˾��൱��"����"��̬��Ա(ͷ�ļ��е��൱�ں�����"����").
// û����һ��, �����õ��˸ó�Ա, ���������.(���Ǳ༭���ǲ�����ʾ��, ���������˶���ֻ���ڱ���ʱ�ڲ��ܷ���.)
// ����ɾ�����������Կɱ���ͨ��.
Animate* Role::animates[4] = { nullptr, nullptr, nullptr, nullptr };
Action* Role::actions[4] = { nullptr, nullptr, nullptr, nullptr };

Role::Role() {
	/*Gravity*  gravity = GravityManager::getInstance()->getGravityByName("role");
	gravity->effectSprite(this);*/
	auto action = MoveBy::create(3.0f,Point(100.0f,0));
	action->retain();
	this->actions[static_cast<int>(Direction::RIGHT)] = action;
}

Role::~Role() {
	for (int i = 0; i < 4; i++) {
		if (Role::animates[i] != nullptr) { // NULL
			Role::animates[i]->release();
		}
		if (Role::actions[i] != nullptr) { // NULL
			CC_SAFE_RELEASE(Role::actions[i]);
			// Role::actions[i]->release();
		}
	}
}

void Role::move(Direction direction) {
	// this->runAction(RepeatForever::create(Role::animates[(int) direction]));
	auto a1 = MoveBy::create(0.1f, Point(10,0));
	auto a2 = MoveBy::create(0.1f, Point(0,10));
	MoveBy* as[2];
	auto s1 = RepeatForever::create(Spawn::create(a1,nullptr));
	auto s2 = RepeatForever::create(Spawn::create(a2,nullptr));
	this->runAction(s1);
	Sleep(2000);
	this->getActionManager()->addAction(s2,this,true);
}

void Role::setMoveAnimate(Direction direction, Animate* animate) {
	Role::animates[(int) direction] = animate;
}

Animate* Role::getAnimate(Direction direction) {
	return Role::animates[(int) direction];
}

Role* Role::create(const std::string& filename, const cocos2d::Rect& rect) {
	Role *sprite = new (std::nothrow) Role();

	if (sprite && sprite->initWithFile(filename, rect)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

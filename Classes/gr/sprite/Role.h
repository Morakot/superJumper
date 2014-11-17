#ifndef __ROLE_H__
#define __ROLE_H__

#include "cocos2d.h"

USING_NS_CC;

enum class Direction;

/****************************************************************************
继承于增强精灵,一般代表主角.
****************************************************************************/
class Role: public Sprite {

private:
	static Animate* animates[4];
	static Action* actions[4];

public:

	// 移动方向
	enum class Direction {
		TOP = 0, BOTTOM = 1, LEFT = 2, RIGHT = 3
	};

	// 状态(普通/无敌)
	enum class Status {
		NORMAL, INVINCIBLE
	};

	Role();

	~Role();

	Animate* getAnimate(Direction);

	void move(Direction);

	void setMoveAnimate(Direction, Animate*);

	static Role* create(const std::string& filename, const cocos2d::Rect& rect);
};

#endif

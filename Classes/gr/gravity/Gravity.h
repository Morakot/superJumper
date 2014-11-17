#ifndef __GRAVITY_H__
#define __GRAVITY_H__

#include "cocos2d.h"

USING_NS_CC;

enum class Mode;

/****************************************************************************
重力系统
****************************************************************************/
class Gravity{

private :

public:

	// 重力模式
	enum class Mode{
		UNIFORM,//匀速
		UNIFORMACCELERATION//匀加速
	};

	// 根据tag标签, 从"重力池"中获取重力模式.
	static Gravity* create(int tag);

	// 设置可以抵抗该重力的障碍物.
	void setObstacle(Sprite*);

	// 使精灵受该重力影响(为精灵添加持久动画).
	void effectSprite(Sprite*);

	// 选取重力模式(匀速、匀加速等)
	void setMode(Mode);
};

#endif
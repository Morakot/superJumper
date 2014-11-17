#ifndef __CCSPRITE_H__
#define __CCSPRITE_H__

#include "cocos2d.h"

namespace gr{

	USING_NS_CC;

	/****************************************************************************
	增强的通用精灵
	****************************************************************************/
	class SpriteX : public Sprite
	{
	private:
		Animate* animate;
		Vec2 speed;

	public:
		SpriteX();
		~SpriteX();

		static SpriteX* create(const std::string& filename);

		void addAnimate(Animate* animate);
		// 支持负值
		void accelerate(Vec2 acc);
		// 减速, 以0为终点.
		void slowDown(Vec2 aac);

		Vec2 getSpeed();

		void setSpeed(Vec2);
	};

};

#endif
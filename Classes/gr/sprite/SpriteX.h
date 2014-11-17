#ifndef __CCSPRITE_H__
#define __CCSPRITE_H__

#include "cocos2d.h"

namespace gr{

	USING_NS_CC;

	/****************************************************************************
	��ǿ��ͨ�þ���
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
		// ֧�ָ�ֵ
		void accelerate(Vec2 acc);
		// ����, ��0Ϊ�յ�.
		void slowDown(Vec2 aac);

		Vec2 getSpeed();

		void setSpeed(Vec2);
	};

};

#endif
#ifndef __ACCELERATER_H__
#define __ACCELERATER_H__

#include "cocos2d.h"

USING_NS_CC;

// 变速运动
class Accelerater : public ActionInterval{
private:
	Vec2 speed;

	// 旧的加速度
	Vec2 formerate;

	Vec2 rate;

	bool initWithRate(Vec2);

	// 时间里程(在每个step,会记下时间里程.相比于elapse,以不断更新的时间里程作为起点可以提供更多控制.)
	DWORD timeMilestone;

	//这里定义一个布尔变量来判断是否是第一次计算时间，相当于一个时间计算方式的开关。  
	bool   m_bFirstTick;

public :
	Accelerater();
	~Accelerater();

	static Accelerater* create(Vec2);

	// Overrides
	virtual void step(float dt) override;
	virtual void update(float time) override;
	virtual Accelerater* clone() const override;
	virtual Accelerater* reverse() const override;

	virtual bool isDone(void) const override;

	// 设置新加速度,并保存旧加速度.
	void Accelerater::setRate(Vec2 rate);

};
#endif
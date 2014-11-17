#ifndef __ACCELERATER_H__
#define __ACCELERATER_H__

#include "cocos2d.h"

USING_NS_CC;

// �����˶�
class Accelerater : public ActionInterval{
private:
	Vec2 speed;

	// �ɵļ��ٶ�
	Vec2 formerate;

	Vec2 rate;

	bool initWithRate(Vec2);

	// ʱ�����(��ÿ��step,�����ʱ�����.�����elapse,�Բ��ϸ��µ�ʱ�������Ϊ�������ṩ�������.)
	DWORD timeMilestone;

	//���ﶨ��һ�������������ж��Ƿ��ǵ�һ�μ���ʱ�䣬�൱��һ��ʱ����㷽ʽ�Ŀ��ء�  
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

	// �����¼��ٶ�,������ɼ��ٶ�.
	void Accelerater::setRate(Vec2 rate);

};
#endif
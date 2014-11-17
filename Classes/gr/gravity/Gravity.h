#ifndef __GRAVITY_H__
#define __GRAVITY_H__

#include "cocos2d.h"

USING_NS_CC;

enum class Mode;

/****************************************************************************
����ϵͳ
****************************************************************************/
class Gravity{

private :

public:

	// ����ģʽ
	enum class Mode{
		UNIFORM,//����
		UNIFORMACCELERATION//�ȼ���
	};

	// ����tag��ǩ, ��"������"�л�ȡ����ģʽ.
	static Gravity* create(int tag);

	// ���ÿ��Եֿ����������ϰ���.
	void setObstacle(Sprite*);

	// ʹ�����ܸ�����Ӱ��(Ϊ������ӳ־ö���).
	void effectSprite(Sprite*);

	// ѡȡ����ģʽ(���١��ȼ��ٵ�)
	void setMode(Mode);
};

#endif
#ifndef __LAYERTOUCHMOVE_H__
#define __LAYERTOUCHMOVE_H__

#include "cocos2d.h"
#include "../includeScene.h"

using namespace cocos2d;

class LayerTouchMove : public Layer
{
private:


public :
	static LayerTouchMove* create();

	bool init() override;
};

#endif

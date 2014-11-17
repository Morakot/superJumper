#ifndef __LAYERCHANGESPEED_H__
#define __LAYERCHANGESPEED_H__

#include "cocos2d.h"
#include "../includeScene.h"

using namespace cocos2d;

class LayerChangeSpeed : public Layer
{
private:


public :
	static LayerChangeSpeed* create();

	bool init() override;
};

#endif

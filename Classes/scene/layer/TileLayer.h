#ifndef __TILELAYER_H__
#define __TILELAYER_H__

#include "cocos2d.h"
#include "../includeScene.h"

using namespace cocos2d;

class TileLayer : public Layer
{
private:


public :
	static TileLayer* create();

	bool init() override;
};

#endif

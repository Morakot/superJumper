#ifndef __GRAVITYMANAGER_H_
#define __GRAVITYMANAGER_H_

#include "cocos2d.h"
#include "Gravity.h"

USING_NS_CC;

/****************************************************************************
重力池
****************************************************************************/
class GravityManager{

private :
	GravityManager();
	~GravityManager();

	// 单例
	static GravityManager* gravityManager;

	//重力库
	std::unordered_map<std::string, Gravity*> gravities;

public:
	static GravityManager* getInstance();

	Gravity* getGravityByName(std::string);

	void addGravity(std::string,Gravity*);
};

#endif
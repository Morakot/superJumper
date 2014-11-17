#ifndef __GRAVITYMANAGER_H_
#define __GRAVITYMANAGER_H_

#include "cocos2d.h"
#include "Gravity.h"

USING_NS_CC;

/****************************************************************************
������
****************************************************************************/
class GravityManager{

private :
	GravityManager();
	~GravityManager();

	// ����
	static GravityManager* gravityManager;

	//������
	std::unordered_map<std::string, Gravity*> gravities;

public:
	static GravityManager* getInstance();

	Gravity* getGravityByName(std::string);

	void addGravity(std::string,Gravity*);
};

#endif
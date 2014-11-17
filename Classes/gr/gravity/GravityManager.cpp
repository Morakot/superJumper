#include "GravityManager.h"
#include<new>
#include<stdio.h>

GravityManager* GravityManager::gravityManager = nullptr;

GravityManager* GravityManager::getInstance()
{
	// TODO:需加多线程锁
	if (!gravityManager){
		gravityManager = new (std::nothrow) GravityManager();
	}
	return gravityManager;
}

GravityManager::GravityManager(){}

GravityManager::~GravityManager(){
	// 遍历gravity, delete
	// this->gravities.
}

Gravity* GravityManager::getGravityByName(std::string name){
	return this->gravities.at(name);
}

void GravityManager::addGravity(std::string name,Gravity* gravity){
	this->gravities[name] = gravity;
}
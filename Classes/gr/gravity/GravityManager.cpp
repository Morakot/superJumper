#include "GravityManager.h"
#include<new>
#include<stdio.h>

GravityManager* GravityManager::gravityManager = nullptr;

GravityManager* GravityManager::getInstance()
{
	// TODO:��Ӷ��߳���
	if (!gravityManager){
		gravityManager = new (std::nothrow) GravityManager();
	}
	return gravityManager;
}

GravityManager::GravityManager(){}

GravityManager::~GravityManager(){
	// ����gravity, delete
	// this->gravities.
}

Gravity* GravityManager::getGravityByName(std::string name){
	return this->gravities.at(name);
}

void GravityManager::addGravity(std::string name,Gravity* gravity){
	this->gravities[name] = gravity;
}
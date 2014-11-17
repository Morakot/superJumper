#include "Accelerater.h"
#include "../graphicrazy.h"
#include <time.h>

USING_NS_CC;

Accelerater* Accelerater::create(Vec2 rate)
{
	Accelerater *action = new Accelerater();
	if (action && action->initWithRate(rate))
	{
		action->autorelease();
		return action;
	}
	CC_SAFE_DELETE(action);
	return nullptr;
}

Accelerater::Accelerater(){
	this->speed = Vec2(0,0);
	this->rate = Vec2(0,0);
	this->formerate = Vec2(0,0);
	this->m_bFirstTick = true;
}

Accelerater::~Accelerater(){

}

void Accelerater::step(float dt)
{
	this->update(dt);
}

void Accelerater::update(float time)
{
	float dt = Director::getInstance()->getAnimationInterval();

	gr::SpriteX* sprite = dynamic_cast<gr::SpriteX*>(this->getTarget());
	if(sprite == nullptr){
		return;
	}

	// 记下时间里程
	/*log("old=%d new=%d delta=%d dt=%f",
	this->timeMilestone,timeGetTime(),timeGetTime()-this->timeMilestone,dt);*/
	this->timeMilestone = timeGetTime();

	// 判断加速度是否改变
	Vec2 thisRate;

	if(this->m_bFirstTick){
		this->m_bFirstTick = false;
		thisRate = this->rate;
		this->formerate = this->rate;
	}else if(this->formerate == this->rate){
		thisRate = this->rate;
	}else{
		thisRate = this->formerate;
		this->formerate = this->rate;
	}

	// 处理x轴运动
	auto speedX = sprite->getSpeed().x;
	auto rateX =  thisRate.x;
	auto averageX = speedX + rateX*dt/2;
	auto deltaDistanceX = averageX * dt;

	// 处理y轴运动
	auto speedY = sprite->getSpeed().y;
	auto rateY =  thisRate.y;
	auto averageY = speedY + rateY*dt/2;
	auto deltaDistanceY = averageY * dt;

	sprite->setPosition(sprite->getPosition()+Vec2(deltaDistanceX,deltaDistanceY));
	sprite->setSpeed(sprite->getSpeed() + thisRate*dt);

	log("x=%f y=%f rate.x=%f rate.y=%f",
		sprite->getSpeed().x,sprite->getSpeed().y,this->rate.x,this->rate.y);
}

bool Accelerater::isDone(void) const
{
	return false;
}

bool Accelerater::initWithRate(Vec2 rate)
{
	// TODO
	ActionInterval::initWithDuration(2.0f);
	this->rate = rate;
	return true;
}

void Accelerater::setRate(Vec2 rate){
	// 引用?
	this->formerate = this->rate;
	this->rate = rate;
}

Accelerater* Accelerater::clone() const {
	return nullptr;
}

Accelerater* Accelerater::reverse() const {
	return nullptr;
}

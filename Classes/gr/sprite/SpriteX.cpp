#include "SpriteX.h"

using namespace gr;

SpriteX* SpriteX::create(const std::string& filename) {
	SpriteX *sprite = new (std::nothrow) SpriteX();

	if (sprite && sprite->initWithFile(filename)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

SpriteX::SpriteX(){

}

SpriteX::~SpriteX(){

}

void SpriteX::addAnimate(Animate* animate){
	this->animate = animate;
}

// ֧�ָ�ֵ
void SpriteX::accelerate(Vec2 acc){
}

// ����, ��0Ϊ�յ�.
void SpriteX::slowDown(Vec2 aac){
}

void SpriteX::setSpeed(Vec2 speed){
	this->speed = speed;
}

Vec2 SpriteX::getSpeed(){
	return this->speed;
}
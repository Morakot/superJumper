#include "TileLayer.h"

USING_NS_CC;
using std::string;

// ��������
TileLayer* TileLayer::create()
{
	TileLayer *ret = new TileLayer();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}

// ��ʼ/������
bool TileLayer::init(){
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ����tilemap
	auto map = TMXTiledMap::create("desert.tmx");
	this->addChild(map, 0);
	//��������
	TMXObjectGroup* objectGroup = map->getObjectGroup("obj0");
	ValueVector object = objectGroup->getObjects();
	for (ValueVector::iterator it = object.begin(); it != object.end(); it++) {
		Value obj = *it;
		ValueMap map = obj.asValueMap();
		log("x = %d y = %d width=%f height=%d", 
			map.at("x").asInt(), map.at("y").asInt(),map.at("width").asFloat(),map.at("height").asInt());
	}

	// ��Ӿ���
	Animate* loadAnimateWith16Grid(string,Role::Direction);
	string filePath = "role.png";
	// ���ö���
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage(filePath);
	Size size = texture->getContentSize();
	Role* role = Role::create(filePath,CCRectMake(0,0,size.width/4,size.height/4));
	this->addChild(role);
	role->setPosition(visibleSize.width/2,visibleSize.height/2);
	Animate* animate = loadAnimateWith16Grid(filePath,Role::Direction::LEFT);
	role->setMoveAnimate(Role::Direction::LEFT,animate);
	animate->retain();
	// animate->autorelease();

	// ��Ӱ���
	JoyStick* joyStick = (JoyStick*)JoyStick::create();
	this->addChild(joyStick);
	Sprite* button = Sprite::create("joystick_direction.png");
	joyStick->setPuppet(role);
	joyStick->addButton(button);

	/******************
	*	chipmunk
	******************/
	// ������������
	auto scene = Scene::createWithPhysics();
	this->addChild(scene);
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//
	auto layer = Layer::create();
	scene->getPhysicsWorld()->setGravity(Vect(0.0f, -98.0f));
	//
	auto PHYSICSBODY_MATERIAL_DEFAULT1 = PhysicsMaterial(10.0f, 0.5f, 0.5f);
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	edgeNode->setPhysicsBody(body);
	scene->addChild(edgeNode);

	// �ӵ�ͼ�м���ש��
	for (ValueVector::iterator it = object.begin(); it != object.end(); it++) {
		Value obj = *it;
		ValueMap map = obj.asValueMap();
		log("x = %d y = %d width=%f height=%d", 
			map.at("x").asInt(), map.at("y").asInt(),map.at("width").asFloat(),map.at("height").asInt());
		float x = map.at("x").asFloat();
		float y = map.at("y").asFloat();
		float w = map.at("width").asFloat();
		float h = map.at("height").asFloat();

		auto body143 = PhysicsBody::createEdgeBox(Size(w,h), PHYSICSBODY_MATERIAL_DEFAULT, 0);
		auto edgeNode144 = Node::create();
		edgeNode144->setPosition(Point(x+w/2,y+h/2));
		edgeNode144->setPhysicsBody(body143);
		scene->addChild(edgeNode144);
	}

	// �ȼ���
	auto acclayer = LayerChangeSpeed::create();
	scene->addChild(acclayer);
}
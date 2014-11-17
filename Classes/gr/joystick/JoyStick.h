#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "cocos2d.h"
#include "..\sprite\role.h"

USING_NS_CC;

// 键盘操纵类
class JoyStick : public Layer{

private:
	// 控制器当前所能控制的节点.
	Node* puppet;

public :
	// 从xml中加载按键配置
	void loadButtonsWithXml(std::string fileName);

	//获取方向键列表(数组)地址
	Sprite* getDirectionButtons();

	// 设置方向键
	void setDirectionButtons();

	void setFunctionButtons();

	// 添加单个按键
	void addButton(Sprite* button);

	static JoyStick* create();

	// 设置控制器当前所能控制的节点.
	void setPuppet(Node* puppet);
	Node* getPuppet();
};

#endif
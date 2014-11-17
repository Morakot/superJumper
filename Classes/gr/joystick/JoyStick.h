#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "cocos2d.h"
#include "..\sprite\role.h"

USING_NS_CC;

// ���̲�����
class JoyStick : public Layer{

private:
	// ��������ǰ���ܿ��ƵĽڵ�.
	Node* puppet;

public :
	// ��xml�м��ذ�������
	void loadButtonsWithXml(std::string fileName);

	//��ȡ������б�(����)��ַ
	Sprite* getDirectionButtons();

	// ���÷����
	void setDirectionButtons();

	void setFunctionButtons();

	// ��ӵ�������
	void addButton(Sprite* button);

	static JoyStick* create();

	// ���ÿ�������ǰ���ܿ��ƵĽڵ�.
	void setPuppet(Node* puppet);
	Node* getPuppet();
};

#endif
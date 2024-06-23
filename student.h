#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<vector>
#include "computerRoom.h"
#include<fstream>
#include "globalfile.h"
#include "orderFile.h"
// �ǥ�
class Student : public Identity
{
public:

	Student();

	//�Ǹ��B�m�W�B�K�X
	Student(int id , string name , string pwd);

	//��椶��
	virtual void operMenu();

	//�ӽйw��
	void applyOrder();

	//�d�ݦۨ��w��
	void showMyOrder();

	//�d�ݩҦ��w��
	void showAllOrder();

	//�����w��
	void cancelOrder();

	//�ǥ;Ǹ�
	int m_Id;

	//���Юe��
	vector<ComputerRoom>vCom;

};
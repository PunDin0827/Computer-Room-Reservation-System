#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include "orderFile.h"
#include<vector>
//�Ѯv
class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int empId , string name , string pwd);

	//��椶��
	virtual void operMenu();

	//�d�ݩҦ��ǥ͹w��
	void showAllOreder();

	//�f�ֹw��
	void validOrder();

	//���u�s��
	int m_empId;

};
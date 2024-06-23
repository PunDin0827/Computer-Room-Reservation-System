#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include "orderFile.h"
#include<vector>
//老師
class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int empId , string name , string pwd);

	//菜單介面
	virtual void operMenu();

	//查看所有學生預約
	void showAllOreder();

	//審核預約
	void validOrder();

	//員工編號
	int m_empId;

};
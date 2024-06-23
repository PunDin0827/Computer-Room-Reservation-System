#pragma once
#include<iostream>
using namespace std;

class Identity
{
public:

	virtual void operMenu() = 0;

	string m_Name; //用戶名稱
	string m_Pwd; //用戶密碼

};

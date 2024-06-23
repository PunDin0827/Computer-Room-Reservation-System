#pragma once
#include<iostream>
using namespace std;
#include "globalfile.h"
#include<fstream>
#include<map>
class orderFile
{
public:

	orderFile();

	//更新預約紀錄
	void updateOrder();

	//記錄預約數
	int m_Size;

	//記錄所有預約的容器  //key:記錄筆數 value:具體記錄鍵值對資訊
	map<int, map<string, string>> m_orderData;

};
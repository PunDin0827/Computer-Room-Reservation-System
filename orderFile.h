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

	//��s�w������
	void updateOrder();

	//�O���w����
	int m_Size;

	//�O���Ҧ��w�����e��  //key:�O������ value:����O����ȹ��T
	map<int, map<string, string>> m_orderData;

};
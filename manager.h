#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include<vector>
#include "student.h"
#include "teacher.h"
#include<algorithm>
#include "computerRoom.h"
//管理員
class Manager : public Identity
{
public:

	Manager();

	Manager(string name , string pwd);

	//菜單介面
	virtual void operMenu();

	//添加帳號
	void addPerson();

	//查看帳號
	void showPerson();

	//查看機房訊息
	void showComputer();

	//清空所有預約紀錄
	void cleanFile();

	//初始化容器
	void initVector();

	//檢測重複 參數1.學號或教職編號    參數2. 檢測類型(學生或老師)
	bool checkRepeat(int id ,int type);

	//存放學生容器
	vector<Student>vStu;

	//存放老師容器
	vector<Teacher>vTea;

	//機房資訊容器
	vector<ComputerRoom>vCom;

};
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
//�޲z��
class Manager : public Identity
{
public:

	Manager();

	Manager(string name , string pwd);

	//��椶��
	virtual void operMenu();

	//�K�[�b��
	void addPerson();

	//�d�ݱb��
	void showPerson();

	//�d�ݾ��аT��
	void showComputer();

	//�M�ũҦ��w������
	void cleanFile();

	//��l�Ʈe��
	void initVector();

	//�˴����� �Ѽ�1.�Ǹ��α�¾�s��    �Ѽ�2. �˴�����(�ǥͩΦѮv)
	bool checkRepeat(int id ,int type);

	//�s��ǥͮe��
	vector<Student>vStu;

	//�s��Ѯv�e��
	vector<Teacher>vTea;

	//���и�T�e��
	vector<ComputerRoom>vCom;

};
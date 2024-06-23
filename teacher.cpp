#include "teacher.h"

Teacher ::Teacher()
{
}
Teacher::Teacher(int empId, string name, string pwd)
{
	//��l���ݩ�
	this->m_empId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//��椶��
void Teacher::operMenu()
{
	cout << "�w��Ѯv" << this->m_Name << "�n��!" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        1.�d�ݩҦ��w��               |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        2.�f�ֹw��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        0.���P�n�J                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "�п�ܱz���ާ@:  " << endl;
}

//�d�ݩҦ��ǥ͹w��
void Teacher::showAllOreder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "�L�w���O��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << ":";
		cout << "�w�����: �P" << of.m_orderData[i]["date"];
		cout << "�ɶ�: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
		cout << "�Ǹ�" << of.m_orderData[i]["stuId"];
		cout << "�m�W" << of.m_orderData[i]["stuName"];
		cout << "���нs��" << of.m_orderData[i]["roomId"];
		string status = "���A: ";
		//1:�f�֤�  2:�w�����\ -1:�w������ 0:�����w��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�f�֤�";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "�w�����\";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "�w�����ѡA�f�֥��q�L";
		}
		else
		{
			status += "�w���w����";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

//�f�ֹw��
void Teacher::validOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "�L�w���O��" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "�ݼf�֪��w���O���p�U: " << endl;

	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ":";
			cout << "�w�����: �P" << of.m_orderData[i]["date"];
			cout << "�w���ɶ�" << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
			cout << "���нs��" << of.m_orderData[i]["roomId"];
			cout << "�ǥ;Ǹ�" << of.m_orderData[i]["stuId"];
			cout << "�ǥͩm�W" << of.m_orderData[i]["stuName"];
			string status = "���A: �f�֤�";
			cout << status << endl;

		}
	}

	cout << "�п�J�f�֪��w���O���A0�N���^" << endl;
	int select = 0; //�����Τ���
	int ret = 0; //�����w�����G

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "�п�J�f�ֵ��G" << endl;
				cout << "1.�q�L" << endl;
				cout << "2.���q�L" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//�f�ֳq�L
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					//�f�֤��q�L
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();  //��s�w���O��
				cout << "�f�֧���" << endl;
				break;
			}	
		}
		cout << "��J���~�A�Э��s��J" << endl;
	}
	system("pause");
	system("cls");
}
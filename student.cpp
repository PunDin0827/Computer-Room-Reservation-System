#include "student.h"

Student::Student()
{
}

//�Ǹ��B�m�W�B�K�X
Student ::Student(int id, string name, string Pwd)
{
	//��l���ݩ�
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = Pwd;

	//��l�ƾ��Юe��
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom Com;
	while (ifs >> Com.m_ComId && ifs >> Com.m_MaxNum)
	{
		//�NŪ�����T����J�e����
		vCom.push_back(Com);
	}
	ifs.close();
	
}
//��椶��
void Student::operMenu()
{
	cout << "�w��ǥͥN��" << this->m_Name << "�n��!" << endl;
	cout << "\t\t-----------------------------------------\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        1.�ӽйw��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        2.�d�ݧڪ��w��               |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        3.�d�ݩҦ��w��               |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        4.�����w��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        0.���P�n��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "�п�ܱz���ާ@:  " << endl;
}
//�ӽйw��
void Student::applyOrder()
{
	cout << "���ж}��ɶ����P�@�ܩP��" << endl;
	cout << "�п�J�ӽйw�����ɶ�" << endl;
	cout << "1.�P�@" << endl;
	cout << "2.�P�G" << endl;
	cout << "3.�P�T" << endl;
	cout << "4.�P�|" << endl;
	cout << "5.�P��" << endl;

	int date = 0; //���
	int interval = 0; //�ɶ�(�W�ȩΤU��)
	int room = 0; //���нs��

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������~�A�Э��s��J" << endl;
	}	
	cout << "�п�J�ӽйw�����ɶ�" << endl;
	cout << "1.�W��" << endl;
	cout << "2.�U��" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "�ɶ����~�A�Э��s��J" << endl;
	}
	cout << "�п�ܾ���" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�����Юe�q��: " << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "���Ц��~�A�Э��s��J" << endl;
	}
	cout << "�w�����\! �f�֤�" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}
//�d�ݦۨ��w��
void Student::showMyOrder()
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

		//string��int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) //���ۤv���w��
		{
			cout << "�w�����: �P" << of.m_orderData[i]["date"];
			cout << " �ɶ���: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
			cout << " ���нs����: " << of.m_orderData[i]["roomId"];
			string status = "���A: ";
			// 1:�f�֤� 2:�w�w�� -1:�w������ 0:�����w��
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
	}
	system("pause");
	system("cls");


}
//�d�ݩҦ��w��
void Student::showAllOrder()
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
		cout << i + 1 << "�A";
		cout << "�w�����: �P" << of.m_orderData[i]["date"];
		cout << " �w���ɶ�: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
		cout << " �Ǹ�: " << of.m_orderData[i]["stuId"];
		cout << " �m�W: " << of.m_orderData[i]["stuName"];
		cout << " ���Ъ��A: " << of.m_orderData[i]["roomId"];
		string status = "���A: ";
		// 1:�f�֤� 2:�w�w�� -1:�w������ 0:�����w��
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
//�����w��
void Student::cancelOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "�L�w���O��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�f�֤��ιw�����\���O���i�H�����A�п�J�������O��" << endl;
	vector<int>v; //�s��b�̤j�e����������
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���P�_�O���O�ۤv���Ǹ�
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//�A�z�窱�A  �f�֤�or�w�����\
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ".";
				cout << "�w�����: �P" << of.m_orderData[i]["date"];
				cout << " �w���ɶ�: " << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
				cout << " ���нs�� " << of.m_orderData[i]["roomId"];
				string status = "���A: ";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�f�֤�";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "�w�����\";
				}
				cout << status << endl;
			}

		}

	}

	cout << "�п�J�������O���A0�N���^" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";

				of.updateOrder();

				cout << "�������\" << endl;
				break;
			}
		}

		cout << "��J���~�A�Э��s��J" << endl;
	}
	system("pause");
	system("cls");
}
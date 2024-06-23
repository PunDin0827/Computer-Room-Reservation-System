#include<iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include "globalfile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//�i�J�ǥͤl��椶��
void studentMenu(Identity*& student)
{
	while (true)
	{
		//�եξǥͤl���
		student->operMenu();
		Student* stu = (Student*)student; 

		int select = 0;
		cin >> select; //�����Τ���

		if (select == 1)
		{
			//�ӽйw��
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//�d�ݦۨ��w��
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			//�d�ݩҦ��H�w��
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			//�����w��
			stu->cancelOrder();
		}
		else
		{
			//���P�n�J
			delete student;
			cout << "���P���\" << endl;
			system("pause");
			system("cls");
			return;
				
		}
	}
}
//�i�J�Ѯv�l��椶��
void teacherMenu(Identity *& teacher)
{
	while (true)
	{
		//�եΤl��椶��
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0; //�����Τ���
		cin >> select;
		
		if (select == 1) //�d�ݩҦ��w��
		{
			tea->showAllOreder();
		}
		else if (select == 2) //�f�ֹw��
		{
			tea->validOrder();
		}
		else //���P
		{
			delete teacher;
			cout << "���P���\" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//�i�J�޲z���l��椶��
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//�եκ޲z���l�����
		manager->operMenu();
		
		//�N����������^�l���A�եΤl����L��f
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����Τ���
		
		cin >> select;

		if (select == 1) //�K�[�b��
		{
			//cout << "�K�[�b��" << endl;
			man->addPerson();
		}
		else if (select == 2) //�d�ݱb��
		{
			//cout << "�d�ݱb��" << endl;
			man->showPerson();
		}
		else if (select == 3) //�d�ݾ��аT��
		{
			//cout << "�d�ݾ���" << endl;
			man->showComputer();
		}
		else if (select == 4) //�M�Źw��
		{
			//cout << "�M�Źw��" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager; //�M��
			cout << "���P���\" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//�n���\�� �Ѽ�1:�ާ@���W�� �Ѽ�2:�ާ@����������
void LoginIn(string fileName, int type)
{
	Identity* Person = NULL;

	//Ū�����
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�P�_���O�_�s�b
	if (!ifs.is_open())
	{
		cout << "��󤣦s�b!" << endl;
		ifs.close();
		return;
	}

	//�ǳƱ����Τ�T��
	int id = 0;
	string name;
	string pwd;

	//�P�_����
	if (type == 1) //�ǥͨ���
	{
		cout << "�п�J�Ǹ�" << endl;
		cin >> id;
	}
	else if (type == 2)//�Ѯv����
	{
		cout << "�п�J�Юv�s��" << endl;
		cin >> id;
	}
	cout << "�п�J�Τ�W��" << endl;
	cin >> name;

	cout << "�п�J�Τ�K�X" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//�ǥͨ�������
		int fid; //���Ū�����ǥ;Ǹ�
		string fname; //���Ū�����ǥͩm�W
		string fpwd; //���Ū�����ǥͱK�X
		while (ifs >>fid && ifs>>fname && ifs>>fpwd)
		{
			//�P�Τ��J���T�������
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "�ǥ����ҵn�J���\!" << endl;
				system("pause");
				system("cls");
				Person = new Student(id,name,pwd);
				
				//�i�J��ǥͨ������l���
				studentMenu(Person);
				
				return;
			}
		}

	}
	else if (type == 2)
	{
		//�Юv��������
		int fid; //���Ū�����Юv�s��
		string fname; //���Ū�����Ѯv�m�W
		string fpwd; //���Ū�����Ѯv�K�X
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//�P�Τ��J���T�������
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "�Юv���ҵn�J���\!" << endl;
				system("pause");
				system("cls");
				Person = new Teacher(id, name, pwd);
				//�i�J�Ѯv�l���
				teacherMenu(Person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//�޲z����������
		string fname; //���Ū�����޲z���m�W
		string fpwd; //���Ū�����޲z���K�X
		while (ifs >> fname && ifs >> fpwd)
		{
			if (name == fname && pwd == fpwd)
			{
				cout << "�޲z�����ҵn�J���\!" << endl;
				system("pause");
				system("cls");
				Person = new Manager(name, pwd);
				
				//�i�J�޲z���l���
				managerMenu(Person);
				
				return;

			}
		}

	}
	cout << "���ҵn�J����" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0; 

	while (true)
	{
		cout << "==========�w��ϥξ��йw���t��==========" << endl;
		cout << endl << "�п�J�z������" << endl;
		cout << "\t\t------------------------\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    1. �ǥͥN��        |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    2. ��    �v        |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    3. �� �z ��        |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    0. �h    �X        |\n";
		cout << "\t\t------------------------\n";
		cout << "�п�J�z�����" << endl;

		cin >> select; //�����Τ���
		switch (select) //�ھڥΤᤣ�P��� ��{���P�覡
		{
		case 1: //�ǥͨ���
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //�Ѯv����
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //�޲z������
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //�h�X�t��
			cout << "�w��U���A�רϥ�! " << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��J���~�A�Э��s���! " << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	
	system("pause");
	return 0;
} 
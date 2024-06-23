#include<iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include "globalfile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//進入學生子菜單介面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//調用學生子菜單
		student->operMenu();
		Student* stu = (Student*)student; 

		int select = 0;
		cin >> select; //接收用戶選擇

		if (select == 1)
		{
			//申請預約
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//查看自身預約
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			//查看所有人預約
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			//取消預約
			stu->cancelOrder();
		}
		else
		{
			//註銷登入
			delete student;
			cout << "註銷成功" << endl;
			system("pause");
			system("cls");
			return;
				
		}
	}
}
//進入老師子菜單介面
void teacherMenu(Identity *& teacher)
{
	while (true)
	{
		//調用子菜單介面
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0; //接收用戶選擇
		cin >> select;
		
		if (select == 1) //查看所有預約
		{
			tea->showAllOreder();
		}
		else if (select == 2) //審核預約
		{
			tea->validOrder();
		}
		else //註銷
		{
			delete teacher;
			cout << "註銷成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//進入管理員子菜單介面
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//調用管理員子類菜單
		manager->operMenu();
		
		//將父類指標轉回子類，調用子類其他街口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用戶選擇
		
		cin >> select;

		if (select == 1) //添加帳號
		{
			//cout << "添加帳號" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看帳號
		{
			//cout << "查看帳號" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看機房訊息
		{
			//cout << "查看機房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空預約
		{
			//cout << "清空預約" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager; //清除
			cout << "註銷成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//登錄功能 參數1:操作文件名稱 參數2:操作的身分類型
void LoginIn(string fileName, int type)
{
	Identity* Person = NULL;

	//讀取文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判斷文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		ifs.close();
		return;
	}

	//準備接收用戶訊息
	int id = 0;
	string name;
	string pwd;

	//判斷身分
	if (type == 1) //學生身分
	{
		cout << "請輸入學號" << endl;
		cin >> id;
	}
	else if (type == 2)//老師身分
	{
		cout << "請輸入教師編號" << endl;
		cin >> id;
	}
	cout << "請輸入用戶名稱" << endl;
	cin >> name;

	cout << "請輸入用戶密碼" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//學生身分驗證
		int fid; //文件讀取的學生學號
		string fname; //文件讀取的學生姓名
		string fpwd; //文件讀取的學生密碼
		while (ifs >>fid && ifs>>fname && ifs>>fpwd)
		{
			//與用戶輸入的訊息做對比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "學生驗證登入成功!" << endl;
				system("pause");
				system("cls");
				Person = new Student(id,name,pwd);
				
				//進入到學生身分的子菜單
				studentMenu(Person);
				
				return;
			}
		}

	}
	else if (type == 2)
	{
		//教師身分驗證
		int fid; //文件讀取的教師編號
		string fname; //文件讀取的老師姓名
		string fpwd; //文件讀取的老師密碼
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//與用戶輸入的訊息做對比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教師驗證登入成功!" << endl;
				system("pause");
				system("cls");
				Person = new Teacher(id, name, pwd);
				//進入老師子菜單
				teacherMenu(Person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理員身分驗證
		string fname; //文件讀取的管理員姓名
		string fpwd; //文件讀取的管理員密碼
		while (ifs >> fname && ifs >> fpwd)
		{
			if (name == fname && pwd == fpwd)
			{
				cout << "管理員驗證登入成功!" << endl;
				system("pause");
				system("cls");
				Person = new Manager(name, pwd);
				
				//進入管理員子菜單
				managerMenu(Person);
				
				return;

			}
		}

	}
	cout << "驗證登入失敗" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0; 

	while (true)
	{
		cout << "==========歡迎使用機房預約系統==========" << endl;
		cout << endl << "請輸入您的身分" << endl;
		cout << "\t\t------------------------\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    1. 學生代表        |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    2. 老    師        |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    3. 管 理 員        |\n";
		cout << "\t\t|                       |\n";
		cout << "\t\t|    0. 退    出        |\n";
		cout << "\t\t------------------------\n";
		cout << "請輸入您的選擇" << endl;

		cin >> select; //接收用戶選擇
		switch (select) //根據用戶不同選擇 實現不同方式
		{
		case 1: //學生身分
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老師身分
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //管理員身分
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //退出系統
			cout << "歡迎下次再度使用! " << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "輸入有誤，請重新選擇! " << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	
	system("pause");
	return 0;
} 
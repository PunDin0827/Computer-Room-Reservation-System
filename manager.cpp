#include "manager.h"
#include "globalfile.h"


Manager::Manager()
{
}

Manager ::Manager(string name, string pwd)
{

	//��l�ƺ޲z��
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��l�Ʈe�� ����Ҧ���� �Ѯv�B�ǥͪ���T
	this->initVector();

	//��l�ƾ��Юe��
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs>>com.m_ComId && ifs>>com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "���мƶq��" << vCom.size() << endl;


}

//��椶��
void Manager::operMenu()
{
	cout << "�w��޲z��: " << this->m_Name << "�n��" << endl;
	cout<<"\t\t-----------------------------------------\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        1.�K�[�b��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        2.�d�ݱb��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        3.�d�ݾ���                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        4.�M�Źw��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|        0.���P�n��                   |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "�п�ܱz���ާ@:  "<< endl;
}

//�K�[�b��
void Manager::addPerson()
{
	cout << "�п�J�K�[�b��������" << endl;
	cout << "1.�K�[�ǥ�" << endl;
	cout << "2.�K�[�Ѯv" << endl;

	string fileName; //�ާ@�����W��
	string tip; //����id�W��
	string errorTip; //���ƿ��~����
	ofstream ofs; //���ާ@��H

	int select = 0;
	cin >> select; //�����Τ�ﶵ
	
	if (select == 1)
	{
		//�K�[�ǥ�
		fileName = STUDENT_FILE;
		tip = "�п�J�Ǹ�";
		errorTip = "�Ǹ����ơA�Э��s��J";
	}
	else
	{
		//�K�[�Ѯv
		fileName = TEACHER_FILE;
		tip = "�п�J��¾�s��";
		errorTip = "��¾�s�����ơA�Э��s��J";
	}
	//�Q�ΰl�[���覡�g�J���
	ofs.open(fileName, ios::out | ios::app);

	int id; //�Ǹ��α�¾�s��
	string name; //�m�W
	string pwd; //�K�X
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) //������
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	
	

	cout << "�п�J�m�W" << endl;
	cin >> name;

	cout << "�п�J�n�J�K�X" << endl;
	cin >> pwd;

	//�V��󤤲K�[�ƾ�

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "�K�[���\" << endl;

	system("pause");
	system("cls");
	
	ofs.close();

	//��l�Ʈe���A���s�����󤤪��ƾ�
	this->initVector();
	

}
void printStudent(Student& s)
{
	cout << "�Ǹ�: " << s.m_Id << endl;
	cout << "�m�W: " << s.m_Name << endl;
	cout << "�K�X: " << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "��¾�s��: " <<t.m_empId  << endl;
	cout << "�m�W: " << t.m_Name << endl;
	cout << "�K�X: " << t.m_Pwd << endl;
}
//�d�ݱb��
void Manager::showPerson()
{
	cout << "�п�ܬd�ݤ��e: " << endl;
	cout << "1.�d�ݩҦ��ǥ�" << endl;
	cout << "2.�d�ݩҦ��Ѯv" << endl;

	int select = 0; //�����Τ���
	cin >> select;
	
	if (select == 1)
	{
		//�d�ݾǥ�
		cout << "�Ҧ��ǥ͸�T�p�U:" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//�d�ݦѮv
		cout << "�Ҧ��Ѯv��T�p�U:" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�d�ݾ��аT��
void Manager::showComputer()
{
	cout << "���и�T�p�U: " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "���нs��: " << it->m_ComId << "���г̤j�e�q: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//�M�ũҦ��w������
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "�M�Ŧ��\ " << endl;
	system("pause");
	system("cls");
}

//��l�Ʈe��
void Manager::initVector()
{
	//�e���M��
	vStu.clear();
	vTea.clear();

	//Ū���ǥ͸�T
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "���Ū������" << endl;
		return;
	}
	
	Student s;
	while (ifs>>s.m_Id && ifs>>s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "�ثe�ǥͼƶq��" << vStu.size() << endl;
	ifs.close();


	//Ū���Юv��T

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs>>t.m_empId && ifs>>t.m_Name && ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "�ثe�Ѯv�ƶq��" << vTea.size() << endl;
	ifs.close();
}
bool Manager::checkRepeat(int id ,int type)
{
	if (type == 1) 
	{
		//�ˬd�ǥ�
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}

	}
	else
	{
		//�ˬd�Ѯv
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empId)
			{
				return true;
			}
		}
	}

	return false;
}
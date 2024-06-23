#include"orderFile.h"

orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;  //日期
	string interval; //時間段
	string stuId; //學生學號
	string stuName; //學生姓名
	string roomId; //預約機房編號
	string status; //預約狀態

	this->m_Size = 0; //預約記錄數量

	while (ifs>>date && ifs>> interval && ifs >>stuId && 
		ifs>>stuName &&ifs>>roomId && ifs>>status)
	{
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomid << endl;
		//cout << status << endl;
		//cout << endl; 

		//date:1
		string key;
		string value;
		map<string, string>m;

		//擷取日期
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		//cout << "key = " << key << endl;
		//cout << "values = " << value << endl;
		
		//擷取時間
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//擷取學生學號
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//擷取學生姓名
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//擷取機房編號
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//擷取預約狀態
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//將小map容器放入大map容器
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
		 
			
	}
	ifs.close();

	//測試大map容器
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "預約筆數: " << it->first << "value=  " << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << " key= " << mit->first << " value = " << mit->second << " ";
	//	}
	//	cout << endl;
	//}

}

//更新預約紀錄
void orderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		//預約記錄0筆
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date: " << this->m_orderData[i]["date"] << " ";
		ofs << "interval:  " << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId: " << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName: " << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId: " << this->m_orderData[i]["roomId"] << " ";
		ofs << "status: " << this->m_orderData[i]["status"] << endl;

	}
	ofs.close();



}

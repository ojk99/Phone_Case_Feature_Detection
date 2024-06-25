#pragma once
#include <iostream>
#include <mysql.h>
#include <vector>
#pragma comment(lib,"libmysql.lib")

class SQL_Query
{
private:
	MYSQL Conn;	//MySQL ������ ���� ����ü
	MYSQL* ConnPtr = NULL;	//MySQL �ڵ�
	MYSQL_RES* Result = NULL;		//���� ������ ����� ��� ����ü������
	MYSQL_ROW Row;			//���� ������ ����� ���� ���� ������ ��� ����ü
	int Stat;

public:
	SQL_Query();

	~SQL_Query();

	std::string TestQuery(); //�׽�Ʈ 

	std::vector<std::vector<MYSQL_ROW>> UserList();

	MYSQL_ROW UserInfo(int userNum);

	MYSQL_ROW UserPhoneInfo(int userNum);

	void InsertUser(std::string id, std::string password);

	void InsertPhone( int h, int width, int height, int userNum);

	std::string SelectPhoneNo(int userNum);

	void UpdatePhoneName(std::string name, int lens, int userNum);

	void UpdateUserPhone(int userNum);

	std::vector<MYSQL_ROW> AllPhoneNum();

	MYSQL_ROW PhoneInfo(std::string phoneNum);
};
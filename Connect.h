#pragma once
#include <iostream>
#include <mysql.h>
#include <vector>
#pragma comment(lib,"libmysql.lib")

class SQL_Query
{
private:
	MYSQL Conn;	//MySQL 정보를 담을 구조체
	MYSQL* ConnPtr = NULL;	//MySQL 핸들
	MYSQL_RES* Result = NULL;		//쿼리 성공시 결과를 담는 구조체포인터
	MYSQL_ROW Row;			//쿼리 성공시 결과로 나온 행의 정보를 담는 구조체
	int Stat;

public:
	SQL_Query();

	~SQL_Query();

	std::string TestQuery(); //테스트 

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
#include <iostream>
#include <mysql.h>
#include "Connect.h"
#include <string>
#pragma comment(lib,"libmysql.lib")
using namespace std;

SQL_Query::SQL_Query()
{
	mysql_init(&Conn);
	ConnPtr = mysql_real_connect(&Conn, "localhost", "root", "0000", "opencv", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << "DB 연결 오류" << endl;
		mysql_close(ConnPtr);
		return;
	}
}

SQL_Query::~SQL_Query()
{
	if (Result != NULL)
	{
		mysql_free_result(Result);
	}

	if (ConnPtr != NULL)
	{
		mysql_close(ConnPtr);
		
	}
	cout << "DB 종료" << endl;
}

std::string SQL_Query::TestQuery()
{
	const char* Query = "SELECT * FROM user";
	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
		string s = "쿼리 에러";
		return s;
	}

	std::string s;
	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		s.append("NO : ").append(Row[0]).append(", ID : ").append(Row[1]).append("\n");
	}
	return s;
}

std::vector<std::vector<MYSQL_ROW>> SQL_Query::UserList()
{
	if (Result != NULL)
	{
		mysql_free_result(Result);
	}
	const char* Query = "SELECT * FROM user";
	Stat = mysql_query(ConnPtr, Query);
	std::vector<std::vector<MYSQL_ROW>> v_sql;
	std::vector<MYSQL_ROW> v;

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		v.push_back(Row);
		v_sql.push_back(v);
	}

	return v_sql;
}

MYSQL_ROW SQL_Query::UserInfo(int userNum)
{
	if (Result != NULL)
	{
		mysql_free_result(Result);
	}
	string s = "SELECT * FROM user WHERE no = ";
	s.append(std::to_string(userNum));
	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}

	Result = mysql_store_result(ConnPtr);
	Row = mysql_fetch_row(Result);

	return Row;
}

MYSQL_ROW SQL_Query::UserPhoneInfo(int userNum)
{
	if (Result != NULL)
	{
		mysql_free_result(Result);
	}
	string s = "SELECT no, h, width, height FROM phone where no = (select phone from user where no = ";
	s.append(std::to_string(userNum).append(")"));
	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}

	Result = mysql_store_result(ConnPtr);
	Row = mysql_fetch_row(Result);

	return Row;
}

void SQL_Query::InsertUser(std::string id, std::string password)
{
	string s = "insert into user(id, user_password) values ('";
	s.append(id).append("\', '").append(password).append("\')");
	const char* Query = s.c_str();
	
	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}

}

void SQL_Query::InsertPhone(int h, int width, int height, int userNum)
{
	string s = "insert into phone(h, width, height, userno) values(";
	s.append(std::to_string(h)).append(", ").append(std::to_string(width)).append(", ")
		.append(std::to_string(height)).append(", ").append(std::to_string(userNum)).append(")");
	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}
}

std::string SQL_Query::SelectPhoneNo(int userNum)
{
	if (Result != NULL)
	{
		mysql_free_result(Result);
	}
	string s = "select phone from user where no = ";
	s.append(to_string(userNum));

	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}

	Result = mysql_store_result(ConnPtr);
	Row = mysql_fetch_row(Result);

	string phoneNo = Row[0];

	return phoneNo;
}

//카메라 렌즈 개수와 휴대폰 이름 업데이트
void SQL_Query::UpdatePhoneName(std::string name, int lens, int userNum)
{
	string s = "update phone set name = '";
	s.append(name).append("\', lens = ").append(std::to_string(lens)).append(" where no = (select phone from user where no = ")
		.append(to_string(userNum).append(")"));

	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}
}

//no 마지막 값을 이용해 유저 정보에 휴대폰 넘버를 저장
void SQL_Query::UpdateUserPhone(int userNum)
{
	string s = "update user set phone = (SELECT Max(no) FROM phone order by no) where no =";
	s.append(std::to_string(userNum));

	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}
}

std::vector<MYSQL_ROW> SQL_Query::AllPhoneNum()
{
	if (Result != NULL)
	{
		mysql_free_result(Result);
	}
	std::vector<MYSQL_ROW> v;
	string s = "select no from phone";

	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}

	Result = mysql_store_result(ConnPtr);


	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		v.push_back(Row);
	}
	return v;
}

MYSQL_ROW SQL_Query::PhoneInfo(std::string phoneNum)
{
	if (Result != NULL)
	{
		mysql_free_result(Result);
	}
	string s = "SELECT no, h, width, height FROM phone where no = ";
	s.append(phoneNum);
	const char* Query = s.c_str();

	Stat = mysql_query(ConnPtr, Query);

	if (Stat != 0)
	{
		cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
	}

	Result = mysql_store_result(ConnPtr);
	Row = mysql_fetch_row(Result);

	return Row;
}
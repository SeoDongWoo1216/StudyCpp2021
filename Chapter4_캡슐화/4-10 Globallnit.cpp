#include <stdio.h>

class DBQuery
{
private:
	static int hCon;
	int nResult;

public:
	DBQuery() {};
	static void DBConnect(const char* Server, const char* ID, const char* Pass);
	static void DBDisConnect();
	bool RunQuery(const char* SQL);
};


int DBQuery::hCon;  // 정적 멤버의 초기값을 안줘도 자동으로 0으로 초기화가 된다.


void DBQuery::DBConnect(const char* Server, const char* ID, const char* Pass)
{
	// 여기서 DB 서버에 접속
	hCon = 1234;
	puts("연결되었습니다.");
}

void DBQuery::DBDisConnect()
{
	// 접속해제
	hCon = NULL;
	puts("연결이 끊어졌습니다.");
}

bool DBQuery::RunQuery(const char* SQL)
{
	// Query(hCon, SQL);
	puts(SQL);
	return true;
}

int main()
{
	DBQuery::DBConnect("Secret", "Adult", "애들은가라");
	DBQuery Q1, Q2, Q3;

	// 필요한 DB 질의를 한다.
	Q1.RunQuery("select * from tblNuja where 나랑 친한 사람");

	DBQuery::DBDisConnect();
}

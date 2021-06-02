/*
	회원이름, 전화번호, 주소, count를 멤버변수로 갖는 class를 설계
	count는 정적 멤버 변수로 작성=> 객체를 생성할때마다 자동으로 1증가
	getdata를 호출하면 저장했던 이름, 번호, 주소, count 출력
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


class CMember
{
private:
	char name[20];
	char phone[15];
	char addr[50];
	static int count;

public:
	// 문자열을 받을때는 원본이라서 const를 붙여줘야함.
	CMember(const char* aname, const char* aphone, const char* aaddr) 
	{ 
		strcpy(this->name, aname);
		strcpy(this->phone, aphone);
		strcpy(this->addr, aaddr);
		count++;
	}
	

	~CMember()
	{ 
		
		cout << "소멸자 호출, 남아있는 회원 수 : " << --count << endl;
	}


	static void InitCount()
	{
		count = 0;
	}


	static void OutCount()
	{
		cout << "현재 회원 수 : " << count << endl;
	}


	void getData() 
	{
		cout << "##### " << count << "번째 회원 #####" << endl;
		cout << "이름 : " << this->name << endl;
		cout << "번호 : " << this->phone << endl;
		cout << "주소 : " << this->addr << endl;
		cout << endl;
	}

};

//static int CMember::count = 0;
int CMember::count;

int main()
{
	CMember::InitCount();

	CMember c1("홍길동", "010-1234-5678", "대한민국 어딘가");
	c1.getData();

	CMember c2("김길동", "010-1111-2222", "한반도 아무데나");
	c2.getData();

	return 0;
}


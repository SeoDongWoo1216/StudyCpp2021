/*
	연산자 오버로딩 예제 문제
	1. Human class만들고 멤버변수로 char *name, int age 선언, 객체 초기화하면더 데이터를 받아보기
	   출력을 담당하는 printHuman(); 만들기
	2. Human youH(myH) 를 성립시키는 복사 생성자 만들기
	3. Human xman
	   xman = myH;     를 성립시키는 대입연산자 멤버함수 만들기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Human
{
private:
	char* name;
	int age;

public:
	Human() 
	{
		this->name = 0;
		this->age = 0;
	}


	// 인자가 2개일때 호출되는 생성자
	Human(const char* name, const int age) // 문자열이므로 *로 받음.
	{
		int len = (strlen(name) + 1);
		this->name = new char[len];   // 멤버변수가 포인터이므로 직접 할당 
		strcpy(this->name, name);     // 문자열은 그대로 들어가지않으므로 strcpy로 복사해서 데이터를 넣어줌

		this->age = age;

		cout << "인자 2개 생성자 호출" << endl;
	}


	// 객체가 왔을때 복사해주는 생성자
	Human(const Human&other)  
	{
		int len = (strlen(other.name) + 1);
		this->name = new char[len];
		strcpy(this->name, other.name);

		this->age = other.age;
		cout << "복사받는 생성자 호출 " << endl;
	}


	// 대입 연산자를 구현하는 생성자 함수
	const Human& operator =(const Human& other)
	{
		int len = (strlen(other.name) + 1);
		this->name = new char[len];
		strcpy(this->name, other.name);

		this->age = other.age;


		cout << "대입연산자 함수 호출" << endl;
		return *this;
	}


	// 소멸자
	~Human()
	{
		delete[] this->name;
		cout << "소멸자 호출" << endl;
	}


	// 데이터 출력
	void printHuman()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl << endl;
	}
};


int main()
{
	Human myH("홍길동", 24);
	myH.printHuman();
	
	Human youH(myH);   // 객체에 복사생성자 적용
	youH.printHuman();

	Human xman;
	xman = myH;       // 객체에 대입연산자 적용
	xman.printHuman();

	cout << endl;
	return 0;
}
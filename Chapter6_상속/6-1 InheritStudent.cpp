#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// 부모 클래스 선언
class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char* name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}

	void intro()
	{
		cout << "이름 : " << this->name << endl;
		cout << "나이 : " << this->age << endl;
	}
};


// 자식 클래스 선언
class Student : public Human  // : 를 통해 상속시켜주는것임
{
private:
	int stunum;

public:
	Student(const char* name, int age, int stunum) : Human(name, age)  // 콜론 초기화
	{
		this->stunum = stunum;
	}

	void study()
	{
		cout << "학번 : " << this->stunum << endl;
		cout << "22는 4, 23은 6, 24 8" << endl;
	}
};

int main()
{
	Human kim("김길동", 29);
	kim.intro();

	Student hong("홍길동", 15, 123456);  // 기존의 클래스를 재사용하면서 123456만 처리하는 클래스를 새로 만듬 -> 재사용성, 상속
	hong.intro();   // Human으로부터 상속받아서 intro를 사용할 수 있음.
	hong.study();
}


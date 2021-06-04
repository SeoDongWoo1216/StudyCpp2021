#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Human
{
protected:
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
		printf("이름 : %s\n", name);
		printf("나이 : %d\n", age);
	}

};

class Student : public Human // public 없이 디폴트값은 private라 상속안되서 접근안됨
{
protected:
	int stunum;

public:
	Student(const char* name, int age, int stunum) : Human(name, age) 
	{
		this->stunum = stunum;
	}

	void study()
	{
		cout << "이이는 사, 이삼은 육, 이사 팔" << endl;
	}

	void report()
	{
		printf("이름 : %s\n", this->name);
		printf("학번 : %d, 보고서 제출\n", this->stunum);
	}

};

int main() 
{
	Student kim("김길동", 20, 123456);
	kim.intro();
	kim.study();
	kim.report();
}

// 상속할때 public을 빼면 기본값으로 private
// 멤버 변수도 디폴트는 private
// 구조체는 디폴트가 public
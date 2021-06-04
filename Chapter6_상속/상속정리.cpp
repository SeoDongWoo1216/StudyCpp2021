/*
	1. Human 부모클래스 선언
	printname를 선언하면

	2. 학생 클래스만들고 휴먼을 상속받기
	학생클래스는 과목(char *major) 선언 후에 printmajor 멤버함수 가짐
	printmajor 출력하면 자기이름, IoT 출력하도록

*/
#include <iostream>
using namespace std;

class Human
{
private:
	char* name;

public:
	Human()
	{
		this->name = 0;
	}
	
	Human(const char *name)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}

	~Human()
	{
		delete[] this->name;
		cout << "소멸자 호출" << endl;
	}

	void printname()
	{
		cout << "My name is " << this->name << endl;
	}
};


class Student : public Human   // Human을 상속받는 Student 클래스 선언
{
private:
	char* major;

public:
	Student()
	{
		this->major = 0;
	}

	Student(const char *name, const char *major) : Human(name)
	{
		int len = strlen(major) + 1;
		this->major = new char[len];
		strcpy_s(this->major, len, major);
	}

	void printMajor()
	{
		printname();
		cout << "My major is " << this->major << endl;
	}
};

int main()
{
	Human my("홍길동");
	my.printname();
	cout << endl;

	Student s("김길동", "IoT");
	s.printMajor();   // My name is 홍길동, My major is IoT
	cout << endl;

	return 0;
}
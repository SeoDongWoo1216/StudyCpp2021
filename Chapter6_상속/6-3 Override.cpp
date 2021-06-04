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
		cout << "이름 : " << this->name << endl;
		cout << "나이 : " << this->age << endl;
	}
};


class Student : public Human
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
		printf("이이는 사, 이삼은 육, 이사는 팔\n");
	}

	void intro()  // 오버라이딩(함수 재정의)
		          // 자식 클래스만의 intro() 함수
	{
		printf("%d학번 %s입니다.\n", this->stunum, this->name);
	}
};

int main()
{
	Human hong("홍길동", 30);
	hong.intro();
	printf("\n");

	Student kim("김길동", 20, 123456);
	kim.intro();
	printf("\n");

	// 자식 클래스인데 이름, 나이만 출력하는 intro()를 출력하고싶다
	// => 자식 클래스 객체인데 부모 클래스의 intro가 필요하다.
	kim.Human::intro();   // => 함수의 소속 클래스를 써주면 가능
	printf("\n");

}
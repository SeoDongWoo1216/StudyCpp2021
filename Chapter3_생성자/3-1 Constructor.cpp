// 파일이름 : Constructor.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


class Human
{
private:
	char name[12];
	int age;

public:
	// 생성자
	Human(const char* aname, int aage) // 클래스의 이름과같고, 리턴값이없으면 생성자이다.
	{
		strcpy(name, aname);
		age = aage;
	}

	void intro() 
	{
		printf("이름 : %s\n", name);
		printf("나이 : %d\n", age);
	}
};

int main() 
{
	Human hong("홍길동", 30);
	hong.intro();
}
// Humancopy.cpp 에서 복사생성자를 생성
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage)
	{
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	Human(const Human &other) // &를 붙이지않으면 무한반복(계속 재귀하게됨)
		                      // &를 붙이지않으면 계속 복사생성자를 호출하게되는것임.
	{
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human()
	{
		delete[] pname;
	}
	
	void intro()
	{
		printf("이름 : %s\n", pname);
		printf("나이 : %d\n", age);
	}
};

void printHuman(Human who)
{
	who.intro();
}


int main()
{
	Human kang("강감찬", 1424);
	Human boy = kang;

	printHuman(boy);
}
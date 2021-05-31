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
		printf("%s 객체의 생성자가 호출되었습니다.\n", pname);
	}

	~Human()
	{
		printf("%s 객체가 파괴되었습니다.\n", pname);
	}

	void intro() 
	{
		printf("이름 : %s\n", pname);
		printf("나이 : %d\n", age);
	}
};

int main() 
{
	Human boy("김수만후거북이와두루미", 12);
	boy.intro();
}
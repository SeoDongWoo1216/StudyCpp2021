#include <stdio.h>

class Human   
{

public:             // private를 통해 은닉
	char name[20];
	int age;

	void intro()
	{
		printf("이름 : %s\n", name);
		printf("나이 : %d\n", age);
	}
};

int main()
{
	Human kim = { "김길동", 30 };

	kim.intro(); 
}
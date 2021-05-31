#include <stdio.h>

struct SHuman
{
	char name[12];
	int age;

	void intro();
};

void SHuman::intro() 
{
	printf("이름 = %s\n", name);
	printf("나이 = %d\n", age);
}

int main() 
{
	SHuman kim = { "홍길동" , 30 };
	kim.intro();
}
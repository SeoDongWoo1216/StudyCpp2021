#include <stdio.h>

class Human
{
public:
	char name[12];
	int age;

	void intro() 
	{
		printf("이름 : %s\n", name);
		printf("나이 : %d\n", age);
	}
};

int main() 
{
	Human arFriend[10] = 
	{
		{"김길동", 49},
		{"홍길동", 49},
		{"최길동", 49}
	};

	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();
}
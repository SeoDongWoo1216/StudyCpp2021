#include <stdio.h>

int main() 
{
	enum origin {EAST, WEST, SOUTH, NORTH};
	// enum origin mark = WEST;

	origin mark = WEST;
	printf("%d 방향\n", mark);

	struct SHuman
	{
		char name[12];
		int age;
		double height;
	};

	// struct SHuman kim = { "홍길동", 30, 200.4 };
	SHuman kim = { "홍길동", 30, 200.4 };
	
	printf("이름 = %s, 나이 = %d\n", kim.name, kim.age);
}
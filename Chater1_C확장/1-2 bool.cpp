#include <stdio.h>

int main() 
{
	int age = 25;
	bool isAdult = age > 19;    // c++에서는 bool형을 지원함.
	if (isAdult) 
	{
		puts("성인입니다");
	}
}
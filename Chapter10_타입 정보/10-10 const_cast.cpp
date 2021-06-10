#include <stdio.h>

int main()
{
	char str[] = "string";
	const char* c1 = str;
	char* c2;
	char* c3;

	const char str1[] = "hello IoT";


	c2 = const_cast<char*>(c1);
	c2[0] = 'a';

	c3 = const_cast<char*>(str1);  // str1을 바로 대입해도됨
	c3[0] = 'H';

	puts(c2);
	puts(c3);

	int num = 10;
	const int& ref = num;
	int& rtem = const_cast<int&>(ref);  // 레퍼런스에도 형변환
	rtem = 30;             // 가능

	printf("%d\n", num);   // 30 출력
}
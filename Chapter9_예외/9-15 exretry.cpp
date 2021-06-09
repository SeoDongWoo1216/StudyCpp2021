
#include <stdio.h>

int main()
{
	int num;

	try
	{
		printf("1~100 정수 입력 : ");
		scanf_s("%d", &num);
		if (num < 1 || num > 100) throw num;
		printf("입력한 수 = %d\n", num);
	}

	catch (int num)
	{
		printf("%d는 1~100 정수가 아닙니다.\n", num);
	}
}
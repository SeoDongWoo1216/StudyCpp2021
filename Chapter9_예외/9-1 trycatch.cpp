#include <stdio.h>

int main()
{
	int a, b;
	try {
		printf("나누어질 수 입력 : ");
		scanf_s("%d", &a);
		if (a < 0) throw a;

		printf("나누는 수 입력 : ");
		scanf_s("%d", &b);
		if (b == 0) throw "0으로는 나눌 수 없습니다.";

		printf("나누기 결과는 %d입니다.", a, b, a / b);
	}

	catch (int a)
	{
		printf("%d는 음수이므로 나누기 거부\n", a);
	}

	catch (const char* message)
	{
		puts(message);
	}
}
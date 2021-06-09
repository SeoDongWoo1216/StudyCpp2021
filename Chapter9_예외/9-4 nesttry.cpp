// 중첩예외처리

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	int num;
	int age;
	char name[128];

	try
	{
		printf("학번 입력 : ");
		scanf("%d", &num);
		if (num <= 0) throw num;
		try
		{
			printf("이름 입력 : ");
			scanf("%s", name);

			if (strlen(name) < 4) throw "이름이 너무 짧습니다.";

			printf("나이 입력 : ");
			scanf("%d", &age);
			if (age <= 0) throw age;
			printf("입력한 정보 => 학번:%d, 이름:%s, 나이:%d\n", num, name, age);
		}

		catch (const char* Message)
		{
			puts(Message);
		}

		catch (int)
		{
			throw;
		}
	}
	catch (int n)
	{
		printf("%d는 음수이므로 적합하지 않습니다.\n", n);
	}
}
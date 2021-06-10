#include <stdio.h>

class Calc
{
public: 
	void Op1(int a, int b) { printf("연산결과 : %d\n", a + b); }
	void Op2(int a, int b) { printf("연산결과 : %d\n", a - b); }
	void Op3(int a, int b) { printf("연산결과 : %d\n", a * b); }
};

void main()
{
	int ch;
	Calc c;
	int a = 3, b = 4;

	printf("연산 방법을 선택하세요. 0 = 더하기, 1 = 빼기, 2 = 곱하기 : ");
	scanf_s("%d", &ch);
	switch (ch)
	{
	case 0:
		c.Op1(a, b);
		break;
	case 1:
		c.Op2(a, b);
		break;
	case 2:
		c.Op3(a, b);
		break;
	}
}
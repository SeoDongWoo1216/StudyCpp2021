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

	void(Calc:: * arop[3])(int, int) = { &Calc::Op1, &Calc::Op2, &Calc::Op3 };

	printf("(Memptr2)연산 방법을 선택하세요. 0 = 더하기, 1 = 빼기, 2 = 곱하기 : ");
	scanf_s("%d", &ch);

	if (ch >= 0 && ch <= 2)
	{
		(c.*arop[ch])(3, 4);
	}

}
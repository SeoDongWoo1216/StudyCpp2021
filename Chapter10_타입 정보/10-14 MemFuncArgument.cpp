#include <stdio.h>

class Calc
{
public:
	void Op1(int a, int b) { printf("연산결과 : %d\n", a + b); }
	void Op2(int a, int b) { printf("연산결과 : %d\n", a - b); }
	void Op3(int a, int b) { printf("연산결과 : %d\n", a * b); }
	void DoCalc(void (Calc::* fp)(int, int), int a, int b)
	{
		puts("연산 결과");
		printf("%d와 %d의 연산 결과 : ", a, b);
		(this->*fp)(a, b);
		puts("연산 결과 끝!");
	}
};

int main()
{
	int ch;
	Calc c;
	int a = 3, b = 4;
	void(Calc:: * arop[3])(int, int) = { &Calc::Op1, &Calc::Op2, &Calc::Op3 };

	printf("연산 방법을 선택하세요. 0 = 더하기, 1 = 빼기, 2 = 곱하기 : ");
	scanf_s("%d", &ch);

	if (ch >= 0 && ch <= 2)
	{
		c.DoCalc(arop[ch], a, b);
	}
}
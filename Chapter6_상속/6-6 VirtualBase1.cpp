#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class A
{
protected:
	int a;
public:
	A(int a) { this->a = a; }
};

class B : public A
{
protected:
	int b;

public:
	B(int a, int b) : A(a) { this->b = b; }
};

class C : public A
{
protected:
	int c;

public:
	C(int a, int c) : A(a) { this->c = c; }
};

class D : public B, public C
{
protected:
	int d;

public:
	D(int a, int b, int c, int d) : B(a, b), C(a, c) { this->d = d; }
	void fD()
	{
		b = 1;
		c = 2;
		a = 3;      // 여기서 문제 발생
	}
};

int main()
{
	D d(1, 2, 3, 4);
}
#include <stdio.h>

class Simple
{
private:
	int value;
	static int count = 0;

public:
	Simple() { count++; }
	~Simple() { count--; }
	void OutCount()
	{
		printf("현재 객체 개수 : %d\n", count);
	}

};

int simple::count = 0;

int main()
{
	Simple s, * ps;
	s.OutCount();
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("크기 : %d\n", sizeof(s));
}
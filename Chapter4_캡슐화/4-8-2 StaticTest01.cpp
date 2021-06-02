#include <iostream>
#include <stdio.h>

class StaticTest
{
public:
	int a;
	static int b;        // static 멤버 변수 선언
	StaticTest()
	{
		a = 10;
		// b = 20;       // 클래스 내부에서는 초기화가 되지않음.(에러)
		b++;             // 생성자가 호출될때마다 b가 1씩 증가함
	}
	
	void getData() 
	{
		printf("a : %d\n", a);
		printf("b : %d\n", b);
	}
};

int StaticTest::b = 20;  // 외부에서 건드릴때는 소속이 필요함.
						 // static 멤버변수 초기화(외부에서 초기화해준것임)
						 // 객체 내에 존재하지 않는다.
int main()
{
	StaticTest s1;
	s1.getData();        // a : 10, b : 21 출력

	StaticTest s2;
	s2.getData();        // a : 10, b : 22 출력

	return 0;
}
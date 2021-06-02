#include <iostream>

class StaticTest
{
	static int a;
	int b;                  // static 멤버 변수 선언
public:
	StaticTest();
	static void setData(int);  // static 멤버 함수는 static 멤버변수에 사용한다.
	void getData();
};


int StaticTest::a = 10;     // static 멤버 변수 초기화


StaticTest::StaticTest()
{
	this->b = 20;
}

void StaticTest::getData()
{
	printf("a : %d, b : %d\n", a, b);
}

void StaticTest::setData(int aa) 
{
	// this->a = aa;  // this->a는 비정적멤버에만 사용할 수 있다.

	// a라는 static 멤버변수는 객체꺼가 아니라서 this를 사용할수없음
	// 클래스꺼임
	a = aa;
}

int main()
{
	StaticTest s1;
	s1.getData();

	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();
	s2.getData();

	// 객체를 사용하지않고 클래스에 소속된 setData(멤버함수) 호출
	StaticTest::setData(40);  // 클래스 소속으로 호출이 가능함.
	s1.getData();             // 출력하니까 a = 40 출력(값이 바뀐것임)
	s2.getData();

	return 0;
}
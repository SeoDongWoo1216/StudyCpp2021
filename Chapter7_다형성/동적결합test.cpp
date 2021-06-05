#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func1() { cout << "B::func1()" << endl; }
	virtual void func2() { cout << "B::func2()" << endl; }
	void func3() { cout << "B::func3()" << endl; }

	// void func1() { cout << "B::func1()" << endl; }
	// void func2() { cout << "B::func2()" << endl; }
};

class Derived : public Base
{
public:
	void func1() { cout << "D::func1()" << endl; }
	void func3() { cout << "D::func3()" << endl; }
	void func4() { cout << "D::func4()" << endl; }

};

int main()
{
	Base b;
	Derived d;

	Base* pb = new Derived;  // 부모객체가 자식객체를 가리키도록 선언

	pb->func1(); // 부모의 func1은 가상함수, 포인터의 객체타입을 따라가서 자식클래스의 func1 이 출력
	pb->func2(); // 부모의 func1은 가상함수, 자식에는 func2가 오버라이드가 안됬기때문에 부모 func2 출력
	pb->func3(); // 부모의 func3이 가상함수가 아니기때문에 포인터자료형을 따라가서 부모클래스의 func3 출력

	return 0;
}
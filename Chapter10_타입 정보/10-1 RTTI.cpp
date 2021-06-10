#include <stdio.h>

class Parent
{
public:
	virtual void PrintMe() { printf("I am Parent\n"); }
};

class Child : public Parent
{
private:
	int num;

public:
	Child(int anum) : num(anum) {}
	virtual void PrintMe() { printf("I am Child\n"); }
	void PrintNum() { printf("Hello Child = %d\n", num); }
};

void func(Parent *p)     
{
	p->PrintMe();             // 타입이 부모를 따라감(근데 가상함수로되어있으면 객체의 자료형을 따라감 => 자식의 프린트미 호출)
	((Child*)p)->PrintNum();
}

int main()
{
	Parent p;    
	Child c(5);  

	func(&c);   // 자식 출력
	func(&p);   // 부모 출력(근데 부모객체에는 num이 없어서 쓰레기값이 출력됨)
}

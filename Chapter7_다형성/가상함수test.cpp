#include <iostream>
using namespace std;


class A
{
public:
	void AFunc()
	{
		cout << "A::AFunc() 입니다." << endl;
	}
};


class B : public A    // B에 A를 상속
{
public:
	void BFunc()
	{
		cout << "B::BFunc() 입니다." << endl;
	}
};


class C : public B     // C에 B를 상속
{
public:
	void CFunc()
	{
		cout << "C::CFunc() 입니다." << endl;
	}
};

int main()
{
	A* pa = new C;   // 기초클래스타입의 포인터가 파생 객체를 가리키고 있다.
	                 // pa의 타입은 C인데 포인터는 A타입
	                 // 부모 객체가 자식 객체를 가리키고있는 것임
	pa->AFunc();


	cout << endl;


	B* pb = new C;
	pb->AFunc();
	pb->BFunc();


	cout << endl;


	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();



	// C* pc2 = new A; // 자식이 부모를 손가락질하는 것은 후레자식이니 에러

	return 0;
}

/*
왜 이짓을 해야하는가?
객체를 사용하면 복사해서 사용 => 메모리를 사용
포인터를하면 복사해서 사용할필요가없음. 
기존의 메모리로 찾아가서 사용만하면 되기때문


부모 포인터는 자식을 가리킬 수 있다.
부모클래스는 자식클래스를 가리킬 수 있다.


포인터를통해 어떤 친구들을 사용할 수 있을까? 가 문제
이때는 포인터의 타입을 따라감
타입이 A타입이면 A      객체에 있는거만 사용가능
타입이 B타입이면 A, B   객체에 있는거 사용가능
타입이 C타입이면 A, B, C객체에 있는거 사용가능




부모 포인터는 자식 객체를 가리킬수있다. (접근이 가능하다)
실질적으로 가리키고 있는 자식객체에 들어간다.
이때 실질적으로 데이터를 사용할 수 있는 부분은 포인터의 타입(자료형)을 따라간다.

데이터를 건드릴때는 포인터의 자료형을 따라간다.
객체 지향언어를 하는데 포인터에 포커스가 맞춰져있다.
만약 A타입으로 접근했지만 A만 쓸 수 있다.
근데 나는 B, C 도 쓰고싶은데 어떻게 할까?

그래서 이것을 해결하려고 쓰는 것이 가상함수(가상클래스)이다.

*/
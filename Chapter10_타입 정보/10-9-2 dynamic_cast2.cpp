#include <iostream>

class A
{
public:
	virtual void test() { printf("A::test()\n"); }
};

class B : public A
{
public:
	virtual void test() { printf("B::test()\n"); }
	void test2() { printf("B::test2()\n"); }
};

class C : public B
{
	virtual void test() { printf("C::test()\n"); }
	void test2() { printf("C::test2()\n"); }
};

void GlobalFunc(A& a)
{
	try
	{
		C& c = dynamic_cast<C&>(a); 
		printf("GlobalFunc()\n");
	}
	catch(std::bad_cast)
	{
		printf("casting error\n");
	}
}

int main()
{
	A* pa = new C;
	A* paa = new B;

	pa->test();                     // C의 test() 출력
	
	B* pb = dynamic_cast<B*>(pa);   // 다운캐스팅
	if (pb) pb->test2();            // B의 test() 출력
	
	C* pc = dynamic_cast<C*>(paa);  // paa는 실제로는 B인데 형변환을통해 C를 가리키도록함 => 자식이 부모를가리킴
	                                // 따라서 이것은 업캐스팅
	// if (pc) pc->test2();

	C c;
	GlobalFunc(c);      // GlobalFunc 출력

	B b;
	GlobalFunc(b);      // 캐스팅 에러

	return 0;
}
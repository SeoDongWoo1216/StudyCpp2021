#include <stdio.h>
#include <typeinfo>

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

void func(){}

int main()
{
	Parent P, * pP;
	Child C(123), * pC;
	pP = &P;
	pC = &C;  

	int val;

	printf("P = %s, pP = %s, *pP = %s\n",
		typeid(P).name(), typeid(pP).name(), typeid(*pP).name());
	printf("C = %s,  pC = %s,  *pC = %s\n",
		typeid(C).name(), typeid(pC).name(), typeid(*pC).name());

	pP = &C;  // 부모 클래스타입 포인터에 자식 클래스 객체를 가리키게함
	          // pP 자체는 부모 클래스 타입의 포인터인데 접근해서 읽어오는 객체는 자식 객체임.
	          // 따라서 pP의 typeid는 부모, *pP의 typeid는 자식이 출력됨

	printf("pP = %s, *pP = %s, val = %s\n",
		typeid(pP).name(), typeid(*pP).name(), typeid(val).name());


	printf("func = %s\n", typeid(func).name());  // 함수의 타입 확인 (cdecl : 함수 규약)
}



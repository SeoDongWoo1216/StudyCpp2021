#include <stdio.h>

class Some
{
private:
	mutable int temp; // const 함수 안에서 변경할 수 있게 해주는 mutable 선언

public:
	Some() {}
	void method() const { temp = 0; }  // const안에서 temp의 값을 변경하려고했는데 에러안뜸
};

int main()
{
	Some s;
	s.method();

	const Some t;
	t.method();
}
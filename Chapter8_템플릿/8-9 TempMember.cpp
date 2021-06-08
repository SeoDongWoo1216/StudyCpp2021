#include <stdio.h>

// template<typename T>   // 클래스 템플릿 => 템플릿 선언을 밖으로꺼내면 클래스가 없으므로 에러뜸
                          // 템플릿자체는 클래스가 될수없고 템플릿이름일뿐임.


class Util
{
public:
	template<typename T>   // 템플릿함수 선언
	void swap(T& a, T& b)
	{
		T t;
		t = a;
		a = b;
		b = t;
	}
};

int main()
{
	//Util<int> u1;    // 템플릿 클래스로했을때
	//Util<double> u2;

	Util u;
	int a = 3;
	int b = 4;
	double c = 1.2;
	double d = 3.4;
	char e = 'e';
	char f = 'f';

	u.swap(a, b);
	u.swap(c, d);
	u.swap(e, f);

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}
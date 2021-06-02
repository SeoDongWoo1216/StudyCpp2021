#include <stdio.h>

class MathCalc
{
private:
	const double pie;  // const 멤버 변수 => 상수화 => 선언과 동시에 초기화

public:
	MathCalc(double apie) : pie(apie) { }  // 콜론 초기화

	// pie가 const라서 생성자 내부에서 초기화할 수 없다.
	// 초기화 되기전에 생성자에다가 콜론 초기화를 시켜주었음.
	// 상수 멤버 변수를 초기화 시켜주는 것임
	 
	// 객체가 생성되는 형태
	// 객체이름으로 메모리 할당 -> 생성자 호출, 초기화
	                                      
	void DoCalc(double r)
	{
		printf("반지름 %.2f인 원의 둘레 : %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}
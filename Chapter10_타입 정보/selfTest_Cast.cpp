#include <iostream>
using namespace std;

int main()
{
	int sum = 124;
	int num = 5;
	printf("평균 : %f", static_cast<double>(sum) / num);

	// 두 값을 연산할때는 두 값의 타입의 통일이 되어야한다.
	// 정수끼리 나누면 정수 나눗셈으로 소수점이 짤린다.
	// 따라서 소수형으로 캐스팅을 해줘야하는데 이때 하나만 캐스팅해주면 자동으로 나머지 하나도 캐스팅된다
	// 정수와 실수는 호환이 가능하기때문에 static_cast 연산자로 double형으로 캐스팅을 해주었다.
}
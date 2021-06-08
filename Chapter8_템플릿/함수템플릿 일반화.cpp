/* 함수 템플릿 : 함수의 틀을 만들어서 여러가지 자료형에 동일한 동작을 적용시켜줌.*/
#include <iostream>
using namespace std;

template<typename T>  // 가장 기본적인 템플릿 형태
T Add(T a, T b)
{
	return a + b;
}


int main()
{
	cout << Add(10, 20) << endl;    // 정수나 실수나 Add를 통해 두 값의 합을 반환받을 수 있음.
	cout << Add(3.14, 4.5) << endl;  
	return 0;
}
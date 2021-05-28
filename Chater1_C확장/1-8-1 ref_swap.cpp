// 두 값을 바꾸는 swab 함수 구현(레퍼런스 사용))
#include <iostream>
using namespace std;

void ref_swab(int &a, int &b);

int main() 
{
	int a = 10;
	int b = 20;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	
	ref_swab(a, b);              // 포인터같은게 아니라 그냥 실인수로 전달

	cout << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
}

void ref_swab(int &x, int &y)   // 매개변수로 레퍼런스를 받음
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
#include <iostream>
using namespace std;

void TestFunc1()
{
	cout << "TestFunc1() 시작" << endl;
	// throw 0;
	cout << "TestFunc1() 종료" << endl;
}

void TestFunc2()
{
	cout << "TestFunc2() 시작" << endl;
	// TestFunc1();
	throw 0;
	cout << "TestFunc2() 종료" << endl;
}

void TestFunc3()
{
	cout << "TestFunc3() 시작" << endl;
	TestFunc2();
	cout << "TestFunc3() 종료" << endl;
}

int main()
{
	try
	{
		TestFunc3();
	}
	catch (...)   // ... 은 모든 타입을 다 받는다는 의미
	{
		cout << "예외 발생" << endl;
	}
	TestFunc1();
	return 0;
}

// 스택풀기 : 함수를 반환하지 않고 스택을 풀어버림.
/*
	객체에 연산을 하기위해 연산자를 직접 만들어보자.
	연산자 함수를 전역함수로 만들어보자.
*/

#include <iostream>
using namespace std;

class MyTest
{
private:
	int x;
	int y;
public:
	MyTest()
	{
		cout << "디폴트 생성자 호출" << endl;
	}

	MyTest(int x, int y)
	{
		this->x = x;
		this->y = y;
		cout << "인수 2개 생성자 호출" << endl;
	}

	const MyTest& operator +(const MyTest& other) const
	{
		MyTest t;
		t.x = this->x + other.x;
		t.y = this->y + other.y;
		return t;
	}

	const MyTest& operator -(const MyTest& other) const
	{
		MyTest t;
		t.x = this->x - other.x;
		t.y = this->y - other.y;
		return t;
	}

	const MyTest& operator =(const MyTest& other) /*const*/
	{
		// MyTest res;
		// res.x = other.x;
		// res.y = other.y;
		// return res;

		x = other.x;
		y = other.y;
		return *this;
	}

	

	void printData()
	{
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
		cout << endl;
	}


	// 전역함수를 사용하기위해 프렌드화
	// 프렌드로해주면 외부에서 접근가능해짐(클래스에서 친구를 맺어준거라 보면됨)
	friend const MyTest operator*(const MyTest& rhs1, const MyTest& rhs2);

};





// 연산자 함수를 전역변수로 만들기
const MyTest operator *(const MyTest& rhs1, const MyTest& rhs2)
{
	MyTest res;
	res.x = rhs1.x * rhs2.x;
	res.y = rhs1.y * rhs2.y;
	return res;
}



int main()
{
	MyTest c1(10, 20);
	MyTest c2(20, 50);
	//MyTest c3;

	//c3 = c1 + c2;
	//c3.printData();   // x : 10 + 20 = 30 출력
	//				  // y : 20 + 50 = 70 출력

	//MyTest c4;
	//c4 = c2 - c1;
	//c4.printData();   // x : 20 - 10 = 10 출력
	//				  // y : 50 - 20 = 30 출력

	MyTest obj;
	//obj = c1.operator=(c2);

	obj = operator*(c1, c2);  // x : 200, y : 1000 출력
	obj.printData();
	
	return 0;
}
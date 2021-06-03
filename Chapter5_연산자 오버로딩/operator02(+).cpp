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

	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y)
	{
		cout << "복사생성자 호출" << endl;
	}

	const MyTest& operator +(const MyTest& other) const
	{
		MyTest t;       // temp 객체를 선언했는데 디폴트 객체가 호출됨
		t.x = this->x + other.x;
		t.y = this->y + other.y;
		return t;       // 객체를 반환할때 임시 객체가 만들어져서 t의 멤버의 값을 복사함
		                // => 복사생성자가 호출됨.
		                // 복사하기위해 임시 객체를 만들어서 복사생성자 호출
		                // 프로그램에는 필요없음 => 성능에 문제가됨
		                // 그래서 출력을 참조형태로 바꾸는것임
		                // 참조형태로 바꾸면 복사생성자가 호출되지않음.

		// # 매개변수, 출력일때 매개변수를 쓸때 레퍼런스를 사용.#
		// 출력타입은 항상 참조형태로 만들어야함
		// 임시객체가 만들어지지않아서 복사생성자가 호출이안됨 => 성능에 도움을 줌
	}

	void printData()
	{
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
	}
};


int main()
{
	MyTest c1(10, 20);
	MyTest c2(20, 50);
	MyTest c3;

	c3 = c1 + c2;
	c3.printData();

	return 0;
}
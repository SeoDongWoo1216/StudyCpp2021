#include <iostream>
using namespace std;
class MyTest
{
private:
	int x;
	int y;

public:
	// 멤버 변수는 만들어서 2개의 객체를 더하는 기능을하는 멤버 함수(Sum) 만들기, 리턴, 입력받음
	MyTest()  // 인자없는 객체를 선언했을때를위한 디폴트 생성자
	{

	}

	MyTest(int x, int y)  // 2개의 인자를 받았을때의 생성자
	{
		this->x = x;
		this->y = y;
	}

	void printData()
	{
		cout << "x : " << this->x << endl;
		cout << "y : " << this->y << endl;
	}

	// 앞의 const는 리턴값이 바뀌면안됨
	// 매개변수 const는 매개변수가 바뀌면안됨
	// 뒤의 const는 this->x, this->y의 값이 바뀌면 안됨
	const MyTest Sum(const MyTest&other) const
	{
		MyTest t;
		t.x = this->x + other.x;
		t.y = this->y + other.y;

		return t;
	}
	
};

int main() 
{
	MyTest obj1(10, 20);
	MyTest obj2(30, 50);
	MyTest obj3;

	obj3 = obj1.Sum(obj2);
	obj3.printData();

	return 0;
}
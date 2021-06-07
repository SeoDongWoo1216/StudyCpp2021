#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int num)
	{
		this->num = num;
		cout << this->num << " CTest 생성자 호출" << endl;

	}

	virtual ~CTest()
	{
		cout << this->num << "CTest 소멸자 호출" << endl;
	}

	virtual void func()
	{
		cout << "CTest function()" << endl;
	}

};


class CTestSub : public CTest
{
private:
	int subN;
public:
	CTestSub(int num, int subN) : CTest(num)
	{
		this->subN = subN;
		cout << this->subN << " CTestSub 생성자 호출" << endl;
	}

	~CTestSub()
	{
		cout << this->subN << " CTestSub 소멸자 호출" << endl;
	}

	void func()
	{
		cout << "CTestSub function()" << endl;
	}

};


int main()
{
	CTest b(10);
	b.func();
	cout << endl;

	CTestSub d(10, 20);
	d.func();
	cout << endl;

	CTest* pb = new CTestSub(30, 33);  // 부모객체가 자식객체를 가리키는 포인터로 선언
	                                  // 추상자료형으로 자식객체를 가리키게함.
	pb->func();                       // 부모꺼가 가상함수 되어있으면 자식 func 호출
	                                  // 부모꺼가 가상함수 안되어있으면 부모 func 호출
	cout << endl;

	delete pb;

	return 0;
}
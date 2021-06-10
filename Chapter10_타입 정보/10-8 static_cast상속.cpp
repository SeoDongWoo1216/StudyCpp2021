#include <iostream>
using namespace std;


class Base
{
private:
	int data;
public:
	Base() {};
	~Base() {};
	void setData(int data)
	{
		this->data = data;
	}
	int getData()
	{
		return this->data;
	}
};


class Derived : public Base
{
public:
	void setData(int data)
	{
		if (data > 0)
		{
			data = 0;
		}
		Base::setData(data);
	}
	void printData()
	{
		cout << "printData() : " << getData() << endl;
	}
};

int main()
{
	Base* pb = new Derived;
	Derived* pd = NULL;

	pb->setData(10);      // 부모클래스의 setData 호출
	// pb->printData();

	pd = static_cast<Derived*>(pb);  // static_cast를 이용해서 자식클래스로 형변환
	pd->setData(20);      // 자식클래스의 setData 호출
	pd->printData();

	return 0;
}


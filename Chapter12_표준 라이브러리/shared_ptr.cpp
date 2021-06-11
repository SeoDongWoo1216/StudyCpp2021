#include <iostream>
using namespace std;
class CTest
{
public:
	CTest() { cout << "CTest()" << endl; };
	~CTest() { cout << "~CTest()" << endl; };
	void func() { cout << "func()" << endl; }
};

int main()
{
	//shared_ptr<CTest> ptr1(new CTest);  
	//ptr1->func();

	//cout << "count : " << ptr1.use_count() << endl;  // 다수개의 메모리를 동적할당할 수 있게 해줌
	//{
	//	shared_ptr<CTest> ptr2(ptr1);
	//	cout << "count : " << ptr1.use_count() << endl; // 여러개를 porting 가능
	//	ptr2->func();
	//}
	//cout << "count : " << ptr1.use_count() << endl;
	


	unique_ptr<CTest> ptr1(new CTest);  //하나만 porting 할수있음(auto_ptr과 비슷한친구임) => 스마트포인터


	return 0;
}
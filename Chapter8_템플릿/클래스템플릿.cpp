// 클래스 템플릿
#include <iostream>
using namespace std;

template <typename T>
class CTest
{
private:
	T num;
public:
	// CTest(T anum) : num(anum) { };
	CTest(T);             // 선언
	void printData()
	{
		cout << "num : " << num << endl;
	}
};

template <typename T>     // 템플릿에서 선언을 한번 더 해주기
CTest<T>::CTest(T anum)   // 생성자를 외부에서 정의하려면 이렇게 해야함.
{

}


int main()
{
	// CTest obj(10);     // 클래스템플릿은 <typename> 을 생략하면 에러
	CTest<int> obj(10);
	obj.printData();
	return 0;
}
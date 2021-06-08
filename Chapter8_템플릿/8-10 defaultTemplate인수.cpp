#include <iostream>
using namespace std;


template <typename T, int sz>
class CTest
{
private:
	T ary[sz];
	int num;

public:
	T& operator[](int idx)             // 객체에서 배열[] 중 [] 연산자는 정의되어있지 않으므로 [] 연산자 오버로딩
	{
		if (idx < 0 || idx >= sz)      // 배열의 크기를 벗어났을때 종료
		{
			cout << "배열의 크기를 벗어났습니다" << endl;
			exit(1);
		}
		return this->ary[idx];
	}

	void getData()
	{
		for (int i = 0; i < sz; i++)
		{
			cout << ary[i] << endl;
		}
	}
};

int main()
{
	CTest<int, 3> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	arr.getData();
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 벡터는 배열의 형태를 가지고있고, 많은 편의성을 제공해준다.
	vector<int> v = { 10,20,30,40,50 };

	// 배열을 출력할때처럼 1행부터 출력
	for (auto i = 0; i < v.size(); i++)  // v.size() : 벡터의 크기
		                                 // auto로 선언하면 어떤 타입이든 받을 수 있음
	{
		cout << v[i] << ' ';
	}

	cout << endl;

	for (auto iter = v.begin(); iter != v.end(); iter++)  // iter는 v의 시작부터 iter가 v의 끝까지될때까지
	{
		cout << *iter << ' ';   // iter가 포인터이므로 *iter로 표기
		                        // 배열로 안써줘도 배열이 출력되는 효과를 볼 수 있음.
	}

	cout << endl;

	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << ' ';      // 우리가 쓰던 표기법
	}



	return 0;
}
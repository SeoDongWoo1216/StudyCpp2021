#include <iostream>
#include <vector>     // 벡터 헤더파일
#include <algorithm>  // sort 헤더파일
using namespace std;

bool compare(int a, int b) { return a > b; }  // 앞의 값이(왼쪽값)이 크게 정렬(내림차순)

int main()
{
	vector<int> arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(6);

	for (auto i = arr.begin(); i < arr.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;

	//sort(arr.begin(), arr.end());        // arr의 시작에서 끝까지 정렬(디폴트로 오름차순)

	sort(arr.begin(), arr.end(), compare);  // return 값에 의해서 정렬해라.
	                                        // 내림차순 정렬

	for (auto i = 0; i < arr.size(); i++)   // auto를 통해 자동으로 컴파일러가 자료형을 맞춰줌
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
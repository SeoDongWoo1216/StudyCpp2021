#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;                       // 배열같이 사용하는것임
	vector<int> v1 = { 1, 2, 3, 4, 5 };  // 초기값을 삽입해서 초기화가능
	vector<int> v2[5];                   // 5개의 방을 가진 v2 생성

	v.push_back(10);  // 기존의 벡터에서 맨마지막 요소에 10을 추가
	
	vector<int> ::iterator iter = v.begin();  // 이터레이터 예약어 : 포인터같은 객체
	                                          // iter라는 iterator 타입의 객체 생성(포인터 같은 객체)
	                                          // iter를 가지고 v에 접근할 수 있음

	iter = v.insert(iter, 2);  // v의 맨 처음에 2 삽입

	v.pop_back();     // v의 맨 마지막에있는 요소 삭제

	v.erase(v.begin() + 10);   // v의 첫번째부터 시작해서 10번째까지의 요소를 삭제

	v.clear();        // v의 모든 원소 제거


	return 0;
}
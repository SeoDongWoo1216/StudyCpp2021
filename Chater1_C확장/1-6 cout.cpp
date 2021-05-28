#include <iostream>   // cout, endl 헤더파일
using namespace std;  //

int main()
{
	// << 는 왼쪽을 오른쪽에 밀어넣어라. 라는 뜻임
	// std::cout << "First C++ Program" << std::endl;  // using문의 std가 없으면 이렇게 써줘야함.
	cout << "First C++ Program" << endl;

	int i = 56;
	char ch = 'S';
	double d = 2.414;

	cout << i << ch << d << endl;
}
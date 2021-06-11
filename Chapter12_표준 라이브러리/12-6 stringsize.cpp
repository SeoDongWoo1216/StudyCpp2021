#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ string");

	cout << s << "문자열의 길이 = " << s.size() << endl;
	cout << s << "문자열의 길이 = " << s.length() << endl;
	cout << s << "문자열의 할당 크기 = " << s.capacity() << endl;
	cout << s << "문자열의 최대 길이 = " << s.max_size() << endl;

	s.resize(6);
	cout << s << "길이 = " << s.size() << ", 할당 크기 = " << s.capacity() << endl;

	s.reserve(100);
	cout << s << "길이 = " << s.size() << ", 할당 크기 = " << s.capacity() << endl;

	cout << s.at(0) << endl;  // 배열의 index를 찾아가려면 at을 사용

	s.clear();
	cout << s << endl;    // clear했기때문에 아무것도 출력안됨
	cout << s << "길이 = " << s.size() << ", 할당 크기 = " << s.capacity() << endl;  
	// size길이는 없어졌지만, capacity의 메모리할당은 남아있음
}
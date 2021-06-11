#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("char array");
	string s2("C++ string");

	cout << s.data() << endl; 
	cout << s.c_str() << endl;  // c 스타일로 만들어줌

	char str[128];
	strcpy_s(str, s.c_str());
	printf("str = %s\n", str);

	swap(s, s2);
	cout << s << endl;
}
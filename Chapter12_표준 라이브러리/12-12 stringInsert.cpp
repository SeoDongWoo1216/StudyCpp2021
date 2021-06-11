#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("123456790");
	string s2("^_^");

	cout << s1 << endl;

	s1.insert(5, "XXX");
	cout << s1 << endl;

	s1.insert(5, s2);
	cout << s1 << endl;

	s1.erase(5, 6);
	cout << s1 << endl;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "독도는 느그땅";

	cout << s1 << endl;
	s1.replace(7, 4, "우리");
	cout << s1 << endl;
}
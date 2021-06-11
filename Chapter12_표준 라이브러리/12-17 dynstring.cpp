#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
	auto_ptr<string> pStr(new string("AutoPtr Test"));

	cout << *pStr << endl;
}
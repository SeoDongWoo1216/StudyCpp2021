#include <stdio.h>

class Parent {};
class Child : public Parent {};

int main()
{
	Parent P, *pP;
	Child C, *pC;
	int i = 1234;

	pP = static_cast<Parent*>(&C);    // 가능
	pC = static_cast<Child*>(&P);     // 가능은하지만 위험
	//pP = static_cast<Parent*>(&i);  // 에러 => 하극상 형태가되면 안됨..
	//pC = static_cast<Child*>(&i);   // 에러
}
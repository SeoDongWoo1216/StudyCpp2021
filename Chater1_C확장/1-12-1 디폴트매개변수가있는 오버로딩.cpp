#include <iostream>

int func(int a)    
{
	return a;
}

int func(int a, int b = 0)   // 디폴트 매개변수를 사용할때는 조심해야함.
{
	return a + b;
}

int main() 
{

	func(10);

	return 0;
}

/*
이렇게 두개의 함수가 존재할때는 컴파일러가 뭘 호출할지 몰라서 오류가뜬다.
첫번째는 매개변수가 하나인경우
두번째는 매개변수가 2개인데 두번째 인수가 디폴트 인수를 사용한경우.
따라서 디폴트 매개변수를 사용할때는 조심해서 사용해야함.
*/
#include <stdio.h>

int main()
{
	const char* str = "korea";
	int* pi;
	double d = 123.456;
	int i;
	int ary[] = { 1, 2, 3, 4, 5 };
	char aary[] = { 'a', 'b' };

	int* ptr = static_cast<int*>(ary);  // 배열은 int형으로 바꿀 수 있다.
	//ptr = static_cast<int*>(aary);    // 포인터끼리의 형변환 => 에러

	i = static_cast<int>(d);        // 가능
	//pi = static_cast<int*>(str);  // 에러 : static_cast는 포인터끼리 형변환은 허용되지않음.
	pi = (int*)str;                 // 가능
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("test");
	string s2(s1);
	string s3;
	string s4(10, 'S');
	string s5("very nice day", 8);

	const char* str = "abcdefghijklmnopqrstuvwxyz";     // 상수이므로 값 변경 불가(그래서 const를 붙이는것임)
	// const char str[] = "abcdefghijklmnopqrstuvwxyz"; // 배열이므로 값 변경 가능( str[0] = D; 이런 형식으로)

	string s6(str + 5, str + 10);  // 5번째부터 10번째까지 문자열을 s6에 저장

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s5 = " << s5 << endl;
	cout << "s6 = " << s6 << endl;
}
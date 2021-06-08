#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <typename T>   // 일반화
T Add(T a, T b)
{
	return a + b;
}

template<>              // 특수화
const char* Add(const char* lstr, const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;   // 맨 마지막에 NULL을 추가해야하므로 + 1해줌

	char* str = new char[len];
	strcpy_s(str, llen + 1, lstr);
	strcat_s(str, len, rstr);
	
	return str;
}

int main()
{
	int res = Add<int>(3, 4);                            // 일반화 템플릿 실행
	cout << res << endl; 
	const char* sres = Add<const char*>("Hello", "IoT"); // 특수화 템플릿 실행
	cout << sres << endl;

	return 0;
}
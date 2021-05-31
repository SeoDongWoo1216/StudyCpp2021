#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human 
{
private:
	char name[12];
	int age;

public:
	Human()    // 디폴트 생성자
	{
		strcpy(name, "이름없음");
		age = 0;
	}
	Human(const char* aname, int aage) 
	{
		strcpy(name, aname);
		age = aage;
	}

	void intro() 
	{
		printf("이름 : %s\n", name);
		printf("나이 : %d\n", age);
	}
};

int main() 
{
	// 디폴트 생성자가 없으면 에러처리됨
	Human momo;          // 에러
	Human arFriend[3];   // 에러

	Human arFriend[3] =
	{
		{ Human("김길동", 30)},
		{ Human("홍길동", 31)},
		{ Human("최길동", 32)}
	};

	arFriend[2].intro();  // 배열의 3번째값 출력(0~2)
}
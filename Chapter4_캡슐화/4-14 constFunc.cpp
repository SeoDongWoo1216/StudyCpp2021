#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s)
	{
		SetTime(h, m, s);
	}

	void SetTime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	// const void OutTime() // 멤버 함수가 상수화됨(출력값이 변경되면 안된다는 의미)
	void OutTime() const    // 멤버 변수의 값을 변경못하게 상수화
	{
		printf("현재 시간은 %d:%d:%d 입니다.\n", hour, min, sec);
		// hour = 24;  // 오류
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00);  // 생성된 객체를 상수화 시킴 => 일반 멤버 함수를 사용할 수 없음
	                                 // const로 상수화시킨 멤버함수만 사용할 수 있음
	// meeting.SetTime(17, 00, 00);  // 객체를 이미 상수화시켰기때문에 SetTime으로 값을 대입하려고하면 오류뜸
	meeting.OutTime();
}
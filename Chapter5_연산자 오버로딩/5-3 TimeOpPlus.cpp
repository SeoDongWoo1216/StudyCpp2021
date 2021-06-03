#include <stdio.h>

class Time
{
	friend const Time operator +(const Time& me, const Time& other);
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime()
	{
		printf("%d:%d:%d\n", hour, min, sec);
	}
};


// 전역의 형태로 오퍼레이터 함수 선언
// 어렵게 생각하지말고 이런 표기법만 기억하고있자
const Time operator +(const Time& me, const Time& other)
{
	Time t;
	t.sec = me.sec + other.sec;
	t.min = me.min + other.min;
	t.hour = me.hour + other.hour;

	t.min += t.sec / 60;
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;
	return t;
}

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1 + t2;
	t3.OutTime();
}
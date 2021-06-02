#include <stdio.h>

class Time;
class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y, month = m, day = d; }
	void OutToday(Time& t);
};


class Time
{
	friend void Date::OutToday(Time&t); // Date:: 로 소속 표시를 해줌
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h, min = m, sec = s; }
};


void Date::OutToday(Time& t)   // 어떤 클래스에 소속되어있는지 Date:: 를 해줌
{
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d 입니다.\n",
		year, month, day, t.hour, t.min, t.sec);
}


int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	d.OutToday(t);
}
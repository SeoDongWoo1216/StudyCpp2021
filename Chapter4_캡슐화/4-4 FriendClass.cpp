#include <stdio.h>

class Date;
class Time
{
	friend class Date;
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h, min = m, sec = s; }

	// Date는 Time의 친구가 아니기때문에 접근이 되지않음.
	// => Time안에서 Date의 멤버변수에 접근할 수 없다.
	/*void OutToday(Date& d)
	{
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d 입니다.\n",
			d.year, d.month, d.day, hour, min, sec);
	}*/
};


class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y, month = m, day = d; }

	// Time은 Date의 친구이다.
	// => Date안에서 Time의 멤버 변수에 접근 가능하다.
	void OutToday(Time& t) 
	{
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d 입니다.\n",
			year, month, day, t.hour, t.min, t.sec);
	}
};


int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	// d.OutToday(t);
	// t.OutToday(d);
}
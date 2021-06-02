#include <stdio.h>

class Date;
class Time
{
	friend void OutToday(Date&, Time&);
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h, min = m, sec = s; }
};


class Date
{
	friend void OutToday(Date&, Time&);  // 프렌드 지정자 사용(접근가능하게해줌)
	                                     // 함수 정의 부분에 friend를 붙여줌.
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y, month = m, day = d; }
};


void OutToday(Date& d, Time& t)  // 객체가 매개변수로 들어갈때는 레퍼런스로 전달해야함.
{
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d 입니다.\n",
		d.year, d.month, d.day, t.hour, t.min, t.sec);
}


int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	OutToday(d, t);
}
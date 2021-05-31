/*
시, 분, 초의 멤버를 가지는 Time 클래스를 정의하듯이
년, 월, 일을 멤버로 가지는 Date 클래스를 정의하라.
오늘 날짜는 출력하는 멤버 함수도 정의한다.
*/

#include <stdio.h>

class Date
{
private:
	int year, mon, day;

public:
	void SetDate(int y, int m, int d)
	{
		year = y;
		mon = m;
		day = d;
	}

	void OutDate() 
	{
		printf("현재 날짜는 %d년 %d월 %d일 입니다.\n", year, mon, day);
	}
};

int main() 
{
	Date now;

	now.SetDate(21, 05, 31);
	now.OutDate();
}
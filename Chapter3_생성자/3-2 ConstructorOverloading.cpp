// 파일이름 : ConstructorOverloading.cpp
#include <stdio.h>

class Time 
{
private:
	int hour, min, sec;

public:
	// 생성자1
	Time(int h, int m, int s) 
	{
		hour = h;
		min = m;
		sec = s;
	}

	// 생성자2
	Time(int abssec) 
	{
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime() 
	{
		printf("현재 시간은 %d:%d:%d 입니다.\n", hour, min, sec);
	}
};

int main() 
{
	Time now(12, 30, 40);
	now.OutTime();
	Time noon(44000);
	noon.OutTime();
}
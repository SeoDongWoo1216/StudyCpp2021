#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime()
	{
		printf("현재 시간은 %d:%d:%d 입니다. \n", hour, min, sec);
	}
};

int main() 
{
	Time now(12, 34, 56);
	Time then = now;

	then.OutTime();
}

/*
우리가 만든 클래스는 새로만든 자료형이라 볼 수 있다.
우리가 만든 클래스는 기존에있는 자료형의 모든 기능처럼 똑같이 수행되어야한다.
따라서 클래스도 복사가 가능해야한다.
왜 되냐? 자동적으로 복사생성자가 호출되기 때문에 자동적으로 필드의 값들을 복사해서 사용해서
동일한 타입의 객체를 만들어서 사용하는게 가능하다.

*/
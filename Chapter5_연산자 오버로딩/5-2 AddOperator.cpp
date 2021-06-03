#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime()
	{
		printf("%d:%d:%d\n", hour, min, sec);
	}

	// operator 키워드를 붙이고 '+'를 함수 이름으로 쓰는것임
	// 앞의 const는 출력값이 변경되면 안된다는 의미.
	// 뒤의 const는 멤버 변수들을 상수화 시켜줌.
	const Time operator + (const Time& other) const  
		// 다른 객체를 불러오는데 객체가 매개변수로 사용되려면 레퍼런스로 갖고와야함
	{
		// 뒤의 const를 붙였는데도 값들이 변경되고, 에러도 안뜸 => t1의 hour, min, sec를 상수화시키는 것임

		// Time t는 지금 여기있는 함수안에서 선언한 것이라 상수화가 적용안됨.
		// other로 가져오는 값은 t2의 값들임

		Time t;
		t.sec = sec + other.sec;
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;

		t.hour += t.min / 60;
		t.min %= 60;
		return t;     // t의 타입은 Time
	}
};

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1 + t2;  // 객체 + 객체로 표기가 가능해짐.
	// t3 = t1.operator+(t2);   // 위에랑 똑같은 코드임.
	// t3 = t1.AddTime(t2);     // 일반 함수 호출할때 코드
	t3.OutTime();
}
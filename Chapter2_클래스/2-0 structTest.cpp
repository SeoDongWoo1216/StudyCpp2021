#include <iostream>

class Human         // 구조체와는 다르게 클래스에 멤버 변수 + 함수 선언
{
public:             // 실제로 클래스 멤버변수는 public이 생략되있음.
	// 멤버 변수 선언
	char name[20];
	int age;
	float height;
	float weight;
	char blood;

	void view();

};

void Human::view()  // 전역함수가 Human 클래스에 소속되어있음을 표시해줌.(범위지정연산자 '::' 사용)
{
	printf("이름   : %s\n", name);
	printf("나이   : %d\n", age);
	printf("신장   : %.2f\n", height);
	printf("체중   : %.2f\n", weight);
	printf("혈액형 : %c\n", blood);
}

int main() 
{
	Human my = { "홍길동", 30, 190, 100, 'A' };

	my.view();  // 클래스에 있는 함수 호출

	return 0;
}
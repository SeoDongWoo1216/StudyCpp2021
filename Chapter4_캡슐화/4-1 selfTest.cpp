/*
	셀프테스트)
	Human 클래스의 멤버 변수를 숨기고 액세서 함수를 작성
	이름이 12미만인 경우만 받아들이고 그 이상은 빈 문자열을 대입한다.
	나이는 0~120 범위만 인정하며 범위 밖의 나이는 0을 대입한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char *name, int age)
	{
		SetName(name);
		Setage(age);
	}

	
	char* GetName(){ return name; }
	void SetName(const char* name)  // 외부에서 값을 전달받을 멤버 함수
	{
		if (strlen(name) < 12) 
		{
			strcpy(this->name, name);
		}
		else
		{
			strcpy(this->name, "");
		}
	}

	int Getage() { return age; }
	void Setage(int age)
	{
		if (age <= 120 && age >= 0)
		{
			this->age = age;
		}
		else
		{
			this->age = 0;
		}
	}

	void printHuman()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl << endl;
	}
};


int main()
{
	/*Human hong;
	hong.SetName("홍길동홍길동홍길동홍길동");
	hong.Setage(138);
	hong.printHuman();

	hong.SetName("길동이");
	hong.Setage(100);
	hong.printHuman();*/

	// 입력연산받아서 해보기
	char tempName[100];
	int tempage;

	cout << "이름 입력 : ";
	cin >> tempName;

	cout << "나이 입력 : ";
	cin >> tempage;

	Human hong(tempName, tempage);
	hong.printHuman();


}
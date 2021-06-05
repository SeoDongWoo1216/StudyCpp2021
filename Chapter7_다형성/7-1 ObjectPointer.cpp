#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}

	void intro()
	{
		printf("이름 : %s\n", this->name);
		printf("나이 : %d\n", this->age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* name, int age, int stunum) : Human(name, age)
	{
		this->stunum = stunum;
	}

	void intro()
	{
		printf("%d 학번 %s 입니다. \n", this->stunum, this->name);
	}

	void study()
	{
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int main()
{
	Human h("김철수", 10);
	Student s("이학생", 15, 1234567);

	Human* pH;
	Student* pS;

	pH = &h;  // 가능 (본인이 본인)
	pS = &s;  // 가능 (본인이 본인)
	pH = &s;  // 가능 (부모자료형포인터가 자식 개체를 가리킴 -> 업캐스팅)
	// pS = &h; // 에러

	pS = (Student*)&h; // 자식이 부모를 가리키는 형태(형변환(다운캐스팅)을 통해)
	pS->intro();
}
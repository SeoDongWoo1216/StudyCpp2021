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
	void study()
	{
		printf("이이는 사, 이삼은 육, 이사 팔 \n");
	}
};

class Graduate : public Student
{
protected:
	char thesis[32];

public:
	Graduate(const char* name, int age, int stunum, const char* thesis) : Student(name, age, stunum)
	{
		strcpy(this->thesis, thesis);
	}

	void research()
	{
		printf("%s을 연구하고 논문을 쓴다.\n", this->thesis);
	}
};

int main()
{
	Graduate hong("홍길동", 45, 900102, "게임방상권분석");
	hong.research();
}
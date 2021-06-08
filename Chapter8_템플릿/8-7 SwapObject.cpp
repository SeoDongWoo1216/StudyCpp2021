#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

template <typename T>
void swap(T& a, T& b)
{
	T t;
	t = a;
	a = b;
	b = t;
}

class Human
{
private:
	char* name;
	int age;

public:
	Human()                                // 디폴트 생성자
	{
		this->name = new char[1];
		name[0] = NULL;
		this->age = 0;
	}

	Human(const char* name, int age)       // 2개의 인자를 가진 생성자
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	Human(const Human& other)              // (참조형태로 매개변수에 들어간) 복사생성자 이면서 변환생성자(인자 1개)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->age = other.age;
	}

	Human& operator =(const Human& other)  // 연산자 오버로딩
	{
		if (this != &other)
		{
			delete[] name;
			this->name = new char[strlen(other.name) + 1];
			strcpy(this->name, other.name);
			this->age = other.age;
		}

		return *this;
	}

	~Human()                               // 소멸자
	{
		delete[] name;
	}

	void intro()                           // 멤버 함수
	{
		printf("이름 : %s\n", this->name);
		printf("나이 : %d\n", this->age);
	}
};


int main()
{
	Human hong("홍길동", 10);
	Human kim("김길동", 20);

	hong.intro();
	kim.intro();
	printf("\n");

	swap(hong, kim);

	hong.intro();
	kim.intro();
	printf("\n");

}
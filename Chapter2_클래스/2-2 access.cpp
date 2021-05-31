#include <stdio.h>

struct SHuman   // 캡슐화, 추상화의 예시로도 볼 수 있다.
{

private:             // private를 통해 은닉
	char name[20];
	int age;

public:
	void intro() 
	{
		printf("이름 : %s\n", name);
		printf("나이 : %d\n", age);
	}
};

int main() 
{
	SHuman kim;

	// kim.age = 300;  // 멤버변수가 private이기때문에 외부에서는 접근할 수 없다. (에러)

	kim.intro();  // public 으로 지정했기때문에 외부에서 호출가능.
}
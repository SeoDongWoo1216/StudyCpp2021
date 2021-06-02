// 멤버 초기화 리스트
// 파일이름 : InitConstMember.cpp
#include <stdio.h>

class Some
{
public:
	const int total;  // 
	Some(int atotal) : total(atotal){}  // const라서
	
	// 일반 변수를 멤버 변수로 초기화시킬때 생성자(근데 total이 const라서 변하는값이아니기때문에 에러임)
	// => 특수한 경우일때는 일반적인 대입연산을 통한 초기화 방식은 안됨.
	/*Some(int atotal)
	{
		total = atotal;
	}*/

	void OutTotal() { printf("%d\n", total); }
};

int main() 
{
	Some S(5);
	S.OutTotal();
}

// 레퍼런스 변수도 선언과 동시에 초기화해줘야함.
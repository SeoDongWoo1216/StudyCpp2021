#include <stdio.h>

int ar[] = { 1,2,3,4,5 };

int& GetAr(int i)   // 콜바이value에 의해 i에 3을 복사해서 저장
{
	return ar[i];   // ar[3]을 리턴 

	//return 3;     // 3이 상수이므로 int&와 맞지않으므로 에러뜸
}

int main() 
{
	// int& ra = 10;  // 상수에는 별명을 줄 수 없음.(에러)

	GetAr(3) = 6;     // 실인수 전달후에 그 변수에 6을 대입
	printf("ar[3] = %d\n", ar[3]);
}

/*
l-value : 변수
R-value : 상수, 배열, 변수

레퍼런스는 항상 l-value에 와야함. => 상수는 레퍼런스가되면 안된다.

C에서는 레퍼런스가 없기때문에 이런것을 쓸수가없었음.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// 이중포인터로 매개변수 전달
//void InputName(char** Name)  
//{
//	*Name = (char*)malloc(32);
//	strcpy(*Name, "Hong Kil Dong");
//}
//
//int main() 
//{
//	char* Name;      // 포인터 선언
//
//	InputName(&Name); 
//	printf("이름은 %s입니다.", Name);
//	free(Name);
//}

//// 레퍼런스로 매개변수 전달
//void InputName(char*&Name)       
//{
//	Name = (char*)malloc(32);
//	strcpy(Name, "Hong Kil Dong");
//}
//
//int main()
//{
//	char* Name;      // 포인터 선언
//
//	InputName(Name);
//	printf("이름은 %s입니다.", Name);
//	free(Name);
//}


int main() 
{
	int a = 10;
	int& ra = a;
	int* pa = &ra;
	printf("%p %p %p\n", &a, &ra, pa);
	// &a  : a의 주소값
	// &ra : 레퍼런스 값이 a의 주소값
	// *pa : pa가 ra를 가리키고있는데 &ra는 a니까 a의 주소값 저장
	
	// 출생신고하면 주민등록번호를 받는다.
	// 레퍼런스는 주민등록번호가아니고 그냥 별명임.

	// 레퍼런스 배열은 선언할 수 없음.

	// 레퍼런스는 중첩할 수 없고 포인터나 배열같은 파생형을 만들 수 없다
	// 레퍼런스는 함수지역변수의 매개변수를 사용할때 사용한다.
	// 함수를통해 지역변수를 건드릴때 레퍼런스를 사용하면 포인터를 사용하는 효과와 같다.
	/
}
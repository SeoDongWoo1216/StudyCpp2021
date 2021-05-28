#include <stdio.h>

int main() 
{
	int i = 3;
	int& ri = i;

	printf("i = %d, ri = %d\n", i, ri);
	ri++;
	printf("i = %d, ri = %d\n", i, ri);
	printf("i번지 = %x, ri번지 = %x\n\n", &i, &ri);

	// pi로 데이터를 건드려보기
	int* pi;
	pi = &i;

	printf("pi의 값 : %d, pi의 주소 : %p\n", pi, &pi);
	printf("pi가 가리키는 값 : %d\n", *pi);

	*pi = i + 1;
	printf("pi의 값 : %d, pi의 주소 : %p\n", pi, &pi);
	printf("pi가 가리키는 값 : %d\n", *pi);
}
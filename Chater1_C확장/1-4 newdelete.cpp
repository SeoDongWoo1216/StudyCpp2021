#include <stdio.h>

int main() 
{
	int* pi, *pj;

	pi = new int;
	pj = new int(10);    // 메모리에 할당하면서 초기화

	*pi = 123;           // 할당한 후에 초기화
	
	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;
	delete pj;
}
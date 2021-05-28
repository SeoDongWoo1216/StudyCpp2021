// 크기가 100인 실수형 배열을 할당하고 50번째 요소에 3.14를 대입하여 출력

#include <stdio.h>

int main() 
{
	double* ar;
	ar = new double[100];
	ar[50] = 3.14;
	printf("ar[50] : %.2f \n", ar[50]);
}
#include <stdio.h>
#include <malloc.h>
#include <memory.h>


// 프로그램이 실행될때 타입이 결정됨 => 동적바인딩
// 함수의 일반화
void swap(void *a, void *b, size_t len)
{
	void* t;
	t = malloc(len);
	memcpy(t, a, len);   // 메모리에 있는 영역을 카피하는 함수
	memcpy(a, b, len);
	memcpy(b, t, len);
	free(t);
}

int main()
{
	int a = 3;
	int b = 4;

	double c = 1.2;
	double d = 3.4;

	swap(&a, &b, sizeof(int));      // void* 타입이라 크기도 인자로 전달해야함.
	swap(&c, &d, sizeof(double));

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f", c, d);
}
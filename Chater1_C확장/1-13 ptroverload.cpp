#include <stdio.h>

void sub(int a)
{
	printf("int : %d\n", a); 
}

void sub(int* a)
{ 
	printf("pointer:%p\n", a); 
}

int main() 
{
	int i = 1234;
	int* pi = &i;

	sub(i);
	sub(pi);
	sub(NULL);        // NULL은 주소값을 가지고있는데 지금 코드에서는 컴파일러가 int로 인식했음
	sub((int*)NULL);  // NULL의 강제 형변환


	// NULL은 정수값 0을 나타내는데 아무것도 가리키지않는 주소를 저장할 수 있는 포인터다.
	// 라고 하기위해서는 NULL도 강제형변환(주소임을 나타내는)을 해줘야함.

	// 오버로딩은 편하긴한데 가급적이면 중복정의를 쓰지않는 것이 좋다.
}



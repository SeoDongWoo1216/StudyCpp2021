// 생성자에대해 딥하게 다뤄보자.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

class cTest
{
private:
    // 멤버변수
    int m_num;
    int* ptr;

public:
    // 생성자
    cTest()           // 디폴트 생성자 생성
    {
        printf("디폴트생성자 호출\n");
    }
        

    cTest(int num)    // 인자 1개를 받는 생성자 선언(변환생성자)
    { 
        m_num = num;           // num으로 받은 인자가 멤버변수 m_num에 저장됨
        cout << "생성자에서 출력됨 : " << m_num << endl;
    }


    cTest(const cTest& other)  // 복사생성자 선언(참조형태의 클래스를 인자로받음)
                               // 함수의 인수로써 클래스를 호출했는데 이때 &를빼면 무한 재귀가되서 주의해야함
                               // 매개변수로 객체가왔으니 본인을 호출하고, 또 본인을 호출하고 ...
                               // 재귀호출을 막기위해 참조형태(&)를 잡아줘야한다.
    {
        this->m_num = other.m_num; // 이 객체(클래스)의 m_num에 인자로받은 m_num을 대입
        this->ptr = new int;       // 동적할당(깊은 복사)
        this->ptr = other.ptr;
        cout << "복사 생성자 호출 : " << m_num << ", " << ptr << endl;
    }


    cTest(int num, int* ptr)   // 인자 2개받는 생성자 선언
    {
        this->m_num = num;     // 이 객체(클래스)의 m_num에 num을 대입
        this->ptr = new int;   // 메모리 동적할당
        this->ptr = ptr;
        cout << "인자 2개받는 생성자 호출 : " << m_num << ", " << ptr << endl;
    }


    ~cTest()   // 소멸자 생성
               // 동적할당한 경우 소멸자에서 해제시켜줌.
    {
        cout << "소멸자 호출" << endl;
        delete ptr;
    }


    void getData()    // 멤버 변수를 출력하기위한 멤버 함수
    {
        cout << endl << "호출한 멤버 변수 : " << m_num << endl;
    }
};

int main() 
{
    // 기본 자료형
    int a = 10;
    int b(20);       // C++에서 제공하는 타입
    int c = a;       // c에 a를 대입(복사)하는게 클래스에서도 가능해야함.


    // 사용자 자료형
    cTest c1(100);   // 인수 1개의 생성자 호출
                     // 인자 1개 받는 생성자가 없음 -> 에러 (디폴트 생성자는 인자가 없기때문)
                     // 생성자를 만들고 인자 1개를 받으면 에러가 없어짐.
                     

    cTest c2;        // 디폴트 생성자 호출        
                     // 디폴트 생성자만 있을때 문제없지만, 인자를받는 생성자만있을때는 에러뜸
                     // 따라서 명시적으로 생성자를 만들면 컴파일러가 기본으로 제공하는 디폴트생성자를 사용할 수 없음.
                     // 근데 디폴트생성자를 우리가 만들어줄수도있음.


    cTest c3(c1);    // 복사생성자 호출(얕은 복사 = 주소를 복사함)
                     // int c = a; 와 같은 원리, 그대로 실행해도 정상적으로 실행은 된다.
                     // 주소를 복사하는 이유 : 참조를 전달받기 때문(참조는 숨겨진 포인터라고 보면됨)
                     // 근데 얕은 복사는 메모리를 동적할당할때 문제가됨.                 
                     
                     
                     
                     // 복사생성자도 자동으로 호출되면서 변수대입처럼 사용할 수 있다. 까지 해도됨


    c3.getData();    // c3 변수 출력


    cTest c4(50, nullptr);  // 2개 인자를받는 생성자가없으면 에러뜸


    cTest c5(c4);    // c4를 복사해서 c5에 대입
                     // 디폴트 복사생성자가 호출됨.

    c5.getData();


    // 기본 자료형 출력
    cout << endl << "----기본 자료형 출력----" << endl;
    cout << "a출력 : " << a << endl;
    cout << "b출력 : " << b << endl;
    cout << "c출력 : " << c << endl << endl;

    return 0;
}


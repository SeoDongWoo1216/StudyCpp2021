#include <iostream>
#include "cursor.h"
using namespace std;

template <typename T>
class PosValue
{
private:
	int x, y;
	T value;

public:
	PosValue(int x, int y, T v) : x(x), y(y), value(v) { }

	void outvalue()
	{
		gotoxy(x, y);
		cout << value << endl;
	}
};

int main()
{
	PosValue<int> iv(10, 10, 2);        // 명시적으로 자료형을 써줌 => 적어준만큼 메모리를 할당해주기때문에 꼭 명시해줘야함
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);

	iv.outvalue();
	cv.outvalue();
	dv.outvalue();
}
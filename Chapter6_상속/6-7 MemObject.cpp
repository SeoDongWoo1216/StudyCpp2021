#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Date
{
protected:
	int year, month, day;
	
public:
	Date(int y, int m, int d) { this->year = y; this->month = m; this->day = d; }
	void OutDate() { printf("%d/%d/%d", this->year, this->month, this->day); }
};


class Product
{
private:
	char name[64];
	char company[32];
	Date validto;
	int price;

public:
	Product(const char* name, const char* company, int y, int m, int d, int price) : validto(y, m, d)
	{
		strcpy(this->name, name);
		strcpy(this->company, company);
		this->price = price;
	}

	void OutProduct()
	{
		printf("이름     : %s\n", this->name);
		printf("제조사   : %s\n", this->company);
		printf("유효기간 : ");
		validto.OutDate();
		puts("");
		printf("가격     : %d\n", this->price);
	}
};

int main()
{
	Product shrimp("새우깡", "농심", 2020, 8, 15, 900);
	shrimp.OutProduct();
}
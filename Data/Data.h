#include <iostream>


class Data
{
private: int day, month, year;

public: Data()
{
		day = 0; 
		month = 0; 
		year = 0;
}
public: Data(int day_, int month_, int year_)
{
	if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0))//Проверка на високосный год
	{
		//leap year
	}
	day = day_;
	month = month_;
	year = year_;
}
};


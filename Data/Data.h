#include <iostream>

class Data
{
	private: unsigned int day, month, year;
	private: bool leap_year;

	public: Data()
	{
			day = 0; 
			month = 0; 
			year = 0;
			leap_year = false;
	}
	public: Data(unsigned int day_, unsigned int month_, unsigned int year_)
	{	
		day = day_;
		month = month_;
		year = year_;

		year += MonthToYears(month);
		DaysInMonth(day, month);
		year += MonthToYears(month);
		if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)))//Проверка на високосный год
		{
			leap_year = true;
		}
		DaysInMonth(day, month);
	}
		  friend std::ostream& operator<< (std::ostream& out, const Data& data);

private: unsigned int MonthToYears(unsigned int& month)
{
	unsigned int years = 0;
	if (month > 12)
	{
		for (; month > 12; month -= 12)
			years++;
	}
	return years;
}
private: void DaysInMonth(unsigned int& day, unsigned int& month)
{
	unsigned int maxDaysInMonth;
	switch (month)
	{
	case 1:maxDaysInMonth = 31; break;
	case 2:
		if (leap_year == true)
			maxDaysInMonth = 29;
		else
			maxDaysInMonth = 28;
		break;
	case 3:maxDaysInMonth = 31; break;
	case 4:maxDaysInMonth = 30; break;
	case 5:maxDaysInMonth = 31; break;
	case 6:maxDaysInMonth = 30; break;
	case 7:maxDaysInMonth = 31; break;
	case 8:maxDaysInMonth = 31; break;
	case 9:maxDaysInMonth = 30; break;
	case 10:maxDaysInMonth = 31; break;
	case 11:maxDaysInMonth = 30; break;
	case 12:maxDaysInMonth = 31; break;

	default:
		break;
	}
	
	for (; day > maxDaysInMonth;)
	{
		day -= maxDaysInMonth;
		month++;
	}
}
};


std::ostream& operator<< (std::ostream& out, const Data& data)
{
	// Поскольку operator << является другом класса Point, то мы имеем прямой доступ к членам Point
	if (data.month < 10)
		out << data.day << ".0" << data.month << "." << data.year;
	else
		out << data.day << "." << data.month << "." << data.year;
	return out;
}
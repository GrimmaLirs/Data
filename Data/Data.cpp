#ifndef  def
#include "Data.h"
#include <vector>
#endif 

using namespace std;

Data Data::operator-- (int)
{
	Data prev = *this;
	--* this;
	return prev;
}

Data Data::operator++ (int)
{
	Data prev = *this;
	++* this;
	return prev;
}

Data& Data::operator-- ()//при уменьшении даты на 1 день стараемся не уйти в нолевые значения в дне и месяце
{
	vector<int> daysInMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leap_year == true)
		daysInMonth[2] = 29;
	if (GetDay() - 1 <= 0)
	{

		if (GetMonth() - 1 <= 0)
		{
			SetMonth(12);
			SetYear(GetYear() - 1);
		}
		else
			SetMonth(GetMonth() - 1);
		SetDay(daysInMonth[month]);
	}
	else
		SetDay(GetDay() - 1);
	return *this;
}

Data Data::operator = (Data data)
{
	this->SetDay(data.GetDay());
	this->SetMonth(data.GetMonth());
	this->SetYear(data.GetYear());
	return data;
}

Data& Data::operator++ ()
{
	this->SetDay(this->GetDay() + 1);
	return *this;
}
void  Data::SetYear(int newYear)
{
	year = newYear;
}
int Data::GetYear()
{
	return this->year;
}

void Data::SetMonth(int newMonth)
{
	month = newMonth;
	TideUp();
}

int Data::GetMonth()
{
	return month;
}

void Data::SetDay(int newDay)
{
	day = newDay;
	TideUp();
}
//геттеры и сеттеры
int Data::GetDay()
	{
		return day;
	}

void Data::TideUp() //Метод для форматирования даты
{
	year += MonthToYears(month);
	DaysToMonth(day, month);
	year += MonthToYears(month);
	if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)))//Проверка на високосный год
	{
		leap_year = true;
	}
	DaysToMonth(day, month);
}

unsigned int Data::MonthToYears(unsigned int& month)
{
	unsigned int years = 0;
	if (month > 12)
	{
		for (; month > 12; month -= 12)
			years++;
	}
	return years;
}

void Data::DaysToMonth(unsigned int& day, unsigned int& month)
{
	vector<int> daysInMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leap_year == true)
		daysInMonth[2] = 29;
	for (; day > daysInMonth[month];)
	{
		day -= daysInMonth[month];
		month++;
	}
}



inline std::ostream& operator<< (std::ostream& out, const Data& dataIn)
{
	// Поскольку operator << является другом класса Data, то мы имеем прямой доступ к членам Data
	if (dataIn.month < 10)
		out << dataIn.day << ".0" << dataIn.month << "." << dataIn.year;
	else
		out << dataIn.day << "." << dataIn.month << "." << dataIn.year;
	return out;
}

inline std::istream& operator>> (std::istream& in, Data& data)
{
	// Поскольку operator>> является другом класса Data, то мы имеем прямой доступ к членам Data.
	// Обратите внимание, параметр Data (объект класса Data) должен быть неконстантным, чтобы мы имели возможность изменить члены класса
	in >> data.day;
	in >> data.month;
	in >> data.year;
	return in;
}

inline Data operator + (Data data, unsigned int days)
{
	data.SetDay(days + data.GetDay());
	return data;
}

inline Data operator += (Data& data, unsigned int days)
{
	data.SetDay(days + data.GetDay());
	return data;
}

inline bool operator == (Data data1, Data data2)
{
	return (data1.GetDay() == data2.GetDay() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() == data2.GetYear());
}
inline bool operator != (Data data1, Data data2)
{
	return (data1.GetDay() != data2.GetDay() || data1.GetMonth() != data2.GetMonth() || data1.GetYear() != data2.GetYear());
}


inline bool operator > (Data data1, Data data2)
{
	return (data1.GetYear() > data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() > data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() > data2.GetYear()));
}

inline bool operator < (Data data1, Data data2)
{
	return (data1.GetYear() < data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() < data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() < data2.GetYear()));
}

inline bool operator >= (Data data1, Data data2)
{
	return (data1.GetYear() >= data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() >= data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() >= data2.GetYear()));
}

inline bool operator <= (Data data1, Data data2)
{
	return (data1.GetYear() <= data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() <= data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() <= data2.GetYear()));
}
#include <iostream>

class Data
{
	private: unsigned int day, month, year;
	private: bool leap_year;

	public: Data()
	{
			day = 1; 
			month = 1; 
			year = 1;
			leap_year = false;
	}
	public: Data(unsigned int day_, unsigned int month_, unsigned int year_)
	{	
		day = day_;
		month = month_;
		year = year_;
		TideUp();
	}
		  friend std::ostream& operator<< (std::ostream& out, const Data& data);
		  friend std::istream& operator>> (std::istream& in, Data& data);

	private: void TideUp() //Метод для форматирования даты
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
//Приводим количество месяцев в порядок 
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

//сколько дней в текущем месяце
	private: int DaysInMonth()
	{
		unsigned int maxDaysInMonth = 0;
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
			maxDaysInMonth = 31;break;	
		}
		return maxDaysInMonth;
	}

	private: void DaysToMonth(unsigned int& day, unsigned int& month)
	{
		for (; day > DaysInMonth();)
		{
			day -= DaysInMonth();
			month++;
		}
	}

	//геттеры и сеттеры
	public: int GetDay()
	{
	   return day;
	}

	public: void SetDay(int newDay)
	{
		day = newDay;
		TideUp();
	}
	public: int GetMonth()
	{
		return month;
	}

	public: void SetMonth(int newMonth)
	{
		month = newMonth;
		TideUp();
	}

	public: int GetYear()
	{
		return this->year;
	}

	public: void SetYear(int newYear)
	{
		year = newYear;
	}
	Data operator = (Data data)
	{
		this->SetDay(data.GetDay());
		this->SetMonth(data.GetMonth());
		this->SetYear(data.GetYear());
		return data;
	}
	// префиксные операторы
	Data& operator++ ()
	{
		this->SetDay(this->GetDay() + 1);
		return *this;
	}
	Data& operator-- ()//при уменьшении даты на 1 день стараемся не уйти в нолевые значения в дне и месяце
	{
		
		if (this->GetDay() - 1 <= 0)
		{
			
			if (this->GetMonth() - 1 <= 0)
			{
				this->SetMonth(12);
				this->SetYear(this->GetYear() - 1);
			}
			else
				this->SetMonth(this->GetMonth() - 1);
			this->SetDay(DaysInMonth());
		}
		else
			this->SetDay(this->GetDay() - 1);
		return *this;
	}
	// постфиксные операторы
	Data operator++ (int)
	{
		Data prev = *this;
		++* this;
		return prev;
	}
	Data operator-- (int)
	{
		Data prev = *this;
		--* this;
		return prev;
	}
};


std::ostream& operator<< (std::ostream& out, const Data& data)
{
	// Поскольку operator << является другом класса Data, то мы имеем прямой доступ к членам Data
	if (data.month < 10)
		out << data.day << ".0" << data.month << "." << data.year;
	else
		out << data.day << "." << data.month << "." << data.year;
	return out;
}

std::istream& operator>> (std::istream& in, Data& data)
{
	// Поскольку operator>> является другом класса Data, то мы имеем прямой доступ к членам Data.
	// Обратите внимание, параметр Data (объект класса Data) должен быть неконстантным, чтобы мы имели возможность изменить члены класса
	in >> data.day;
	in >> data.month;
	in >> data.year;
	return in;
}

Data operator + (Data data, unsigned int days)
{
	data.SetDay(days + data.GetDay());
	return data;
}

Data operator += (Data& data, unsigned int days)
{
	data.SetDay(days + data.GetDay());
	return data;
}

bool operator == (Data data1, Data data2)
{
	return (data1.GetDay() == data2.GetDay() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() == data2.GetYear());
}
bool operator != (Data data1, Data data2)
{
	return (data1.GetDay() != data2.GetDay() || data1.GetMonth() != data2.GetMonth() || data1.GetYear() != data2.GetYear());
}


bool operator > (Data data1, Data data2)
{
	return (data1.GetYear() > data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() > data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() > data2.GetYear()));
}

bool operator < (Data data1, Data data2)
{
	return (data1.GetYear() < data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() < data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() < data2.GetYear()));
}

bool operator >= (Data data1, Data data2)
{
	return (data1.GetYear() >= data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() >= data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() >= data2.GetYear()));
}

bool operator <= (Data data1, Data data2)
{
	return (data1.GetYear() <= data2.GetYear() || (data1.GetYear() == data2.GetYear() && data1.GetMonth() <= data2.GetMonth()) || (data1.GetYear() == data2.GetYear() && data1.GetMonth() == data2.GetMonth() && data1.GetYear() <= data2.GetYear()));
}
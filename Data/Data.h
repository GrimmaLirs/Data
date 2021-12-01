#include <iostream>


class Data
{
	private: 
		unsigned int day, month, year;
		bool leap_year;
		inline void TideUp();
		inline unsigned int MonthToYears(unsigned int& month);//Приводим количество месяцев в порядок 
		inline void DaysToMonth(unsigned int& day, unsigned int& month);
	


	public: 
		inline Data() : day(1), month(1), year(1), leap_year(false)
		{
		}
		inline Data(unsigned int day_, unsigned int month_, unsigned int year_) : day(day_), month(month_), year(year_), leap_year(false)
		{
			TideUp();
		}
			  friend std::ostream& operator<< (std::ostream& out, const Data& data);
			  friend std::istream& operator>> (std::istream& in, Data& data);

		//геттеры и сеттеры
		inline int GetDay();
		inline void SetDay(int newDay);
		inline int GetMonth();
		inline void SetMonth(int newMonth);
		inline int GetYear();
		inline void SetYear(int newYear);
	
		inline Data operator = (Data data);
			// префиксные операторы
		inline Data& operator++ ();
		inline Data& operator-- ();
			// постфиксные операторы
		inline Data operator++ (int);
		inline Data operator-- (int);
};
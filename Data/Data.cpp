#include "Data.h"

int Data::DaysInMonth()
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
			maxDaysInMonth = 31; break;
		}
		return maxDaysInMonth;
	
}

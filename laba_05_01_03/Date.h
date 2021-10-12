#pragma once
#include <iostream>
class Date
{
private:
	size_t day = 0, 
		month = 0,
		year = 0;
public:
	Date();
	Date(size_t day, size_t month, size_t year);
	void set_date(size_t day, size_t month, size_t year);
	size_t get_day();
	size_t get_month();
	size_t get_year();

	friend std::istream& operator>> (std::istream& in, Date& V);
};

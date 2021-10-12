#include "Date.h"

Date::Date(){}

Date::Date(size_t day, size_t month, size_t year):day(day),month(month),year(year){}

void Date::set_date(size_t day, size_t month, size_t year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

size_t Date::get_day()
{
	return day;
}

size_t Date::get_month()
{
	return month;
}

size_t Date::get_year()
{
	return year;
}

std::istream& operator>>(std::istream& in, Date& V)
{
		in >> V.day >> V.month >> V.year;
	return in;
}

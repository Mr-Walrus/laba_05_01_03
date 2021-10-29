#include "Poet.h"

Poet::Poet(std::string FIO, Date burth, Date death) : Writer(FIO), burth(burth), death(death) 
{
	std::cout << "Poet(std::string FIO, Date burth, Date death)\n\tstring FIO: " << FIO << endl
		<< "\tDate burth: " << burth.to_str() << endl
		<< "\tDate death: " << death.to_str() << endl;
}

Poet::~Poet()
{
	std::cout << "~Poet()\n";
}

Date Poet::get_burth_date()
{
	return burth;
}

Date Poet::get_death_date()
{
	return death;
}

std::string Poet::get_data()
{
	std::string out = "Poet\n" + FIO + "\n" 
		+ to_string(burth.get_day()) + " " 
		+ to_string(burth.get_month()) + " " 
		+ to_string(burth.get_year()) + "\n"
		+ to_string(death.get_day()) + " " 
		+ to_string(death.get_month()) + " " 
		+ to_string(death.get_year()) + "\n"
		+ to_string(works.size()) + "\n";
	for (size_t i = 0; i < works.size(); i++)
		out += works[i] + "\n";
	return out;
}

std::string Poet::get_print_data()
{
	std::string out = "\tПоэт\n\t\t" + FIO + "\n\t\t"
		+ to_string(burth.get_day()) + "."
		+ to_string(burth.get_month()) + "."
		+ to_string(burth.get_year());
	if (death.get_day() + death.get_month() + death.get_year() != 0)
		out += " - " + to_string(death.get_day()) + "."
		+ to_string(death.get_month()) + "."
		+ to_string(death.get_year());
	out += "\n\t\tОсновные произведения:";
	for (size_t i = 0; i < works.size(); i++)
		out += "\n\t\t\t" + works[i];
	return out;
}

#include "Novelist.h"

Novelist::Novelist(std::string FIO, Date burth, Date death, std::string biography) : Writer(FIO), burth(burth), death(death), biography(biography)
{
	std::cout << "Novelist(std::string FIO, Date burth, Date death, std::string biography)\n\tstring FIO: " << FIO << endl
		<< "\tDate burth: " << burth.to_str() << endl
		<< "\tDate death: " << death.to_str() << endl
		<< "\tstring biography: " << biography << endl;
}

Novelist::~Novelist()
{
	std::cout << "~Novelist()\n";
}

Date Novelist::get_burth_date()
{
	return burth;
}

Date Novelist::get_death_date()
{
	return death;
}

std::string Novelist::get_biography()
{
	return biography;
}

std::string Novelist::get_data()
{
	std::string out = "Novelist\n" + FIO + "\n"
		+ to_string(burth.get_day()) + " "
		+ to_string(burth.get_month()) + " "
		+ to_string(burth.get_year()) + "\n"
		+ to_string(death.get_day()) + " "
		+ to_string(death.get_month()) + " "
		+ to_string(death.get_year()) + "\n"
		+ biography + "\n"
		+ to_string(works.size()) + "\n";
	for (size_t i = 0; i < works.size(); i++)
		out += works[i] + "\n";
	return out;
}

std::string Novelist::get_print_data()
{
	std::string out = "\tРоманист\n\t\t" + FIO + "\n\t\t"
		+ to_string(burth.get_day()) + "."
		+ to_string(burth.get_month()) + "."
		+ to_string(burth.get_year());
	if (death.get_day() + death.get_month() + death.get_year() != 0)
		out += " - " + to_string(death.get_day()) + "."
		+ to_string(death.get_month()) + "."
		+ to_string(death.get_year());
	out += "\n\t\tБиография:\n\t\t" + biography + 
		+ "\n\t\tОсновные произведения:";
	for (size_t i = 0; i < works.size(); i++)
		out += "\n\t\t\t" + works[i];
	return out;
}

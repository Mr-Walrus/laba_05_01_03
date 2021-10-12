#include "Science_fiction.h"

Science_fiction::Science_fiction(std::string FIO, bool film) :Writer(FIO), film(film) {}

bool Science_fiction::has_film()
{
	return film;
}

void Science_fiction::set_film(bool film)
{
	this->film = film;
}

std::string Science_fiction::get_data()
{
	std::string out = "Science_fiction\n" + FIO + "\n"
		+ to_string(film) + "\n"
		+ to_string(works.size()) + "\n";
	for (size_t i = 0; i < works.size(); i++)
		out += works[i] + "\n";
	return out;
}

std::string Science_fiction::get_print_data()
{
	std::string out = "\t�������\n\t\t" + FIO
		+ "\n\t\t����� �� ������ �� ������ - " + (film ? "��" : "���")
		+ "\n\t\t�������� ������������:";
	for (size_t i = 0; i < works.size(); i++)
		out += "\n\t\t\t" + works[i];
	return out;
}

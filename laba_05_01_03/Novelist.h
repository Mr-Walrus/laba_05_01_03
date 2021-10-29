#pragma once
#include "Writer.h"
#include "Date.h"
class Novelist : public Writer
{
private:
	Date burth, death;
	std::string biography;
public:
	Novelist(std::string FIO, Date burth, Date death, std::string biography);
	~Novelist();
	Date get_burth_date();
	Date get_death_date();
	std::string get_biography();
	virtual std::string get_data() override;
	virtual std::string get_print_data() override;
};
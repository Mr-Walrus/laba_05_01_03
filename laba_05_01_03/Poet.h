#pragma once
#include "Writer.h"
#include "Date.h"
class Poet : public Writer
{
private:
	Date burth, death;
public:
	Poet(std::string FIO, Date burth, Date death);
	~Poet();
	Date get_burth_date();
	Date get_death_date();
	virtual std::string get_data() override;
	virtual std::string get_print_data() override;
};
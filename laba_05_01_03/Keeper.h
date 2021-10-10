#pragma once
#include <fstream>
#include <string>
#include "Printing.h"
#include "Writer.h"
class Keeper
{
private:
	Printing* printings;
public:
	~Keeper();
	void save_to_file(std::string);
	int  load_from_file(std::string);
	void add_printing();
	void add_writer(size_t i_i, Writer* w);
	void remove_printing(size_t i_i);
	void remove_writer(size_t i_i, size_t j_j);
	void print_data();
};
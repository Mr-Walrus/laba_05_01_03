#pragma once
#include <fstream>
#include <string>
#include "Date.h"
#include "Printing.h"
#include "Writer.h"
#include "Poet.h"
#include "Science_fiction.h"
#include "Novelist.h"
#include "Double_List.h"
class Keeper
{
private:
	List<Printing*> printings;
public:
	Keeper();
	~Keeper();
	void save_to_file(std::string);
	int  load_from_file(std::string);
	void add_printing();
	void add_writer(size_t i_i, Writer* w);
	void remove_printing(size_t i_i);
	void remove_writer(size_t i_i, size_t j_j);
	size_t get_printing_amm();
	size_t get_writer_amm(size_t i_i);
	void print_data();
};
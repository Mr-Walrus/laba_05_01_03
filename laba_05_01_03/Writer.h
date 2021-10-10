#pragma once
#include <string>
class Writer
{
protected:
	std::string FIO;
	std::string* works;
public:
	Writer(std::string FIO);

	void set_FIO(std::string FIO);
	std::string get_FIO();
	void add_work(std::string work);
	std::string remove_work(size_t i_i);
	virtual std::string get_data() = 0;
	virtual std::string get_print_data() = 0;
};
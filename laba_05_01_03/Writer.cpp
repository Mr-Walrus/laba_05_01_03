#include "Writer.h"

Writer::Writer(std::string FIO) : FIO(FIO) {}

void Writer::set_FIO(std::string FIO)
{
	this->FIO = FIO;
}

std::string Writer::get_FIO()
{
	return FIO;
}

void Writer::add_work(std::string work)
{
	works.push_back(work);
}

std::string Writer::remove_work(size_t i_i)
{
	return works.pop(i_i);
}

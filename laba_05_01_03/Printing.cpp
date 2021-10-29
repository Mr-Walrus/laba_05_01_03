#include "Printing.h"

Printing::Printing()
{
	std::cout << "Printing()\n";
}

Printing::~Printing()
{
	std::cout << "~Printing()\n";
	if (writers.size())
		for (size_t i = 0; i < writers.size(); i++)
			delete writers[i];
}

void Printing::add_element(Writer* W)
{
	writers.push_back(W);
}

void Printing::remove_element(size_t i_i)
{
	writers.pop(i_i);
}

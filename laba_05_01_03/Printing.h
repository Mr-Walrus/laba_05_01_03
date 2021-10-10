#pragma once
#include "Writer.h"
class Printing
{
private:
	Writer* writers;
public:
	~Printing();

	void add_element(Writer* W);
	void remove_element(size_t i_i);

	friend class Keeper;
};
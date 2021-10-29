#pragma once
#include "Writer.h"
#include "Double_List.h"
class Printing
{
private:
	List<Writer*> writers;
public:
	Printing();
	~Printing();

	void add_element(Writer* W);
	void remove_element(size_t i_i);

	friend class Keeper;
};
#pragma once
#include "Writer.h"
class Science_fiction : public Writer
{
private:
	bool film = false;
public:
	Science_fiction(std::string FIO, bool film);
	~Science_fiction();
	bool has_film();
	void set_film(bool film);
	virtual std::string get_data() override;
	virtual std::string get_print_data() override;
};
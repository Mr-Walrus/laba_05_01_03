#include "Keeper.h"

Keeper::~Keeper()
{
	if (printings.size())
		for (size_t i = 0; i < printings.size(); i++)
			delete printings[i];
}

void Keeper::save_to_file(std::string file)
{
	std::ofstream fout(file);
	if (!fout) return;
	fout << to_string(printings.size()) << "\n";
	for (size_t i = 0; i < printings.size(); ++i)
	{
		fout << to_string(printings[i]->writers.size()) << "\n";
		for (size_t j = 0; j < printings[i]->writers.size(); ++j)
		{
			fout << printings[i]->writers[j]->get_data();
		}
	}

	fout.close();
}

int Keeper::load_from_file(std::string file)
{
	std::ifstream fin(file);
	if (!fin) return 1;
	size_t printings_size;
	size_t writers_size;
	size_t num;
	std::string type;
	std::string FIO;
	std::string biography;
	std::string work;
	Date burth, death;

	fin >> printings_size;
	for (size_t i = 0; i < printings_size; i++)
	{
		fin >> writers_size;
		Printing* temp = new Printing;
		for (size_t j = 0; j < writers_size; j++)
		{
			fin >> type;
			getline(fin, FIO);
			getline(fin, FIO);
			if (type == "Poet")
			{
				fin >> burth;
				fin >> death;
				fin >> num;
				getline(fin, work);
				Poet* p = new Poet(FIO, burth, death);
				for (size_t i = 0; i < num; i++)
				{
					getline(fin, work);
					p->add_work(work);
				}
				temp->writers.push_back(p);
			}
			else if (type == "Novelist")
			{
				fin >> burth;
				fin >> death;
				getline(fin, biography);
				getline(fin, biography);
				fin >> num;
				getline(fin, work);
				Novelist* n = new Novelist(FIO, burth, death, biography);
				for (size_t i = 0; i < num; i++)
				{
					getline(fin, work);
					n->add_work(work);
				}
				temp->writers.push_back(n);
			}
			else if (type == "Science_fiction")
			{
				bool film;
				fin >> film;
				fin >> num;
				getline(fin, work);
				Science_fiction* s = new Science_fiction(FIO, film);
				for (size_t i = 0; i < num; i++)
				{
					getline(fin, work);
					s->add_work(work);
				}
				temp->writers.push_back(s);
			}
		}
		printings.push_back(temp);
	}

	fin.close();
	return 0;
}

void Keeper::add_printing()
{
	printings.push_back(new Printing);
}
void Keeper::add_writer(size_t i_i, Writer* w)
{
	printings[i_i]->writers.push_back(w);
}

void Keeper::remove_printing(size_t i_i)
{
	printings.pop(i_i);
}

void Keeper::remove_writer(size_t i_i, size_t j_j)
{
	printings[i_i]->writers.pop(j_j);
}

void Keeper::print_data()
{
	for (size_t i = 0; i < printings.size(); ++i)
	{
		std::cout << "\nИздательство №" << i + 1;
		for (size_t j = 0; j < printings[i]->writers.size(); ++j)
		{
			std::cout << "\n\tПисатель №" << j + 1 << endl
				<< printings[i]->writers[j]->get_print_data();
		}
	}
}

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Keeper.h"
#include "Printing.h"
#include "Writer.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

/*

Разработать класс Keeper, который реализует контейнер для хранения и обработки объектов.
Класс Keeper должен обеспечивать следующие функции:
	▪ добавление и удаление производных объектов абстрактного класса Base;
	▪ полное сохранение себя в файле;
	▪ полное восстановление себя из файла.

Класс Печатное издание (Printing)(Base) хранит книги поэтов, романистов и фантастов.
	Poet:				ФИО, годы жизни, несколько произведений.
	Novelist:			ФИО, годы жизни, несколько произведений, краткая биография.
	Science_fiction:	ФИО, несколько произведений, сняты ли фильмы по книгам.

*/
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

	Keeper kipper;
	int c;

	while (1)
	{
		cout << "Меню"
			<< "\n1.Восстановление из файла"
			<< "\n2.Добавить печатное издание"
			<< "\n3.Добавить писателя:"
			<< "\n4.Вывод данных на экран"
			<< "\n5.Удалить печатное издание"
			<< "\n6.Удалить писателя:"
			<< "\n7.Сохранение в файл"
			<< "\n0.Выход без сохранения\n->";
		cin >> c;

		switch (c)
		{
		case 1: kipper.load_from_file("load.txt"); break;
		case 2: kipper.add_printing(); break;
		case 3: kipper.add_writer(); break;
		case 4: kipper.print_data(); break;
		case 5: kipper.remove_printing(); break;
		case 6: kipper.remove_writer(); break;
		case 7: kipper.save_to_file("save.txt"); break;
		case 0:	cout << "\t\t  Все несохраненные данные будут утеряны!"
			<< "\n\t\t  Продолжить?(1-Да / 0-Нет)\n\t\t->";
			cin >> c;
			if (c == 1) return 0;
		}
	}

}

/*

Разработать класс Keeper, который реализует контейнер для хранения и обработки объектов.
Класс Keeper должен обеспечивать следующие функции:
	▪ добавление и
	▪ удаление производных объектов абстрактного класса Base;
	▪ полное сохранение себя в файле;
	▪ полное восстановление себя из файла.

Класс Печатное издание (Printing)(Base) хранит книги поэтов, романистов и фантастов.
	Poet:				ФИО, годы жизни, несколько произведений.
	Novelist:			ФИО, годы жизни, несколько произведений, краткая биография.
	Science_fiction:	ФИО, несколько произведений, сняты ли фильмы по книгам.

*/
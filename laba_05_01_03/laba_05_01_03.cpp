#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Double_List.h"
#include "Date.h"
#include "Keeper.h"
#include "Printing.h"
#include "Writer.h"
#include "Poet.h"
#include "Science_fiction.h"
#include "Novelist.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper kipper;
	int c;

	while (true)
	{
		cout << "\nМеню"
			<< "\n1.Восстановление из файла"
			<< "\n2.Добавить печатное издание"
			<< "\n3.Добавить писателя"
			<< "\n4.Вывод данных на экран"
			<< "\n5.Удалить печатное издание"
			<< "\n6.Удалить писателя"
			<< "\n7.Сохранение в файл"
			<< "\n0.Выход без сохранения\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			if (kipper.load_from_file("save.txt"))
				cout << "\tДанные успешно загружены\n";
			else
				cout << "\tФайл не найден или повреждён\n";
			break; }
		case 2: {
			kipper.add_printing();
			cout << "\tПечатное издание №" << kipper.get_printing_amm() << " успешно добавлено\n";
			break; }
		case 3: {
			if (kipper.get_printing_amm() == 0)
				cout << "\tПечатные издания отсутствуют. Добавтье печатное издание.\n";
			else
			{
				int num;
				cout << "\tВыбирите печатное издание. Доступны: №"
					<< (kipper.get_printing_amm() == 1 ? "" : "1 - №")
					<< (kipper.get_printing_amm() == 1 ? 1 : kipper.get_printing_amm())
					<< "\n\t->";
				cin >> num;				
				try
				{
					std::string FIO;
					int type;
					cout << "\tВыбирите писателя:\n"
						<< "\n\t1.Поэт:"
						<< "\n\t2.Романист"
						<< "\n\t3.Фантаст\n\t->";
					cin >> type;
					switch (type)
					{
					case 1: {
						Date burth; Date death;
						cout << "\tВведите ФИО: ";
						getline(cin, FIO);
						getline(cin, FIO);
						cout << "\tВведите дату рождения (дд мм гггг): ";
						cin >> burth;
						cout << "\tВведите дату смерти (дд мм гггг): ";
						cin >> death;
						Writer* writer = new Poet(FIO, burth, death);
						kipper.add_writer(num - 1, writer);
						cout << "\tПисатель №" << kipper.get_writer_amm(num - 1) << " успешно добавлен\n";
						break; }
					case 2: {
						bool film;
						char f;
						cout << "\tВведите ФИО: ";
						getline(cin, FIO);
						getline(cin, FIO);
						cout << "\tБыли ли сняты фильмы по его произведениям(д/н): ";
						cin >> f;
						film = f == 'д' || f == 'Д';
						Writer* writer = new Science_fiction(FIO, film);
						kipper.add_writer(num - 1, writer);
						cout << "\tПисатель №" << kipper.get_writer_amm(num - 1) << " успешно добавлен\n";
						break; }
					case 3: {
						Date burth; Date death; std::string biography;
						cout << "\tВведите ФИО: ";
						getline(cin, FIO);
						getline(cin, FIO);
						cout << "\tВведите дату рождения: ";
						cin >> burth;
						cout << "\tВведите дату смерти: ";
						cin >> death;
						cout << "\tВведите биографию: ";
						getline(cin, biography);
						getline(cin, biography);
						Writer* writer = new Novelist(FIO, burth, death, biography);
						kipper.add_writer(num - 1, writer);
						cout << "\tПисатель №" << kipper.get_writer_amm(num - 1) << " успешно добавлен\n";
						break; }
					default: cout << "\tВыбрано недопустимое значение!\n";
					}
				}
				catch (int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 4: {
			kipper.print_data();
			break; }
		case 5: {
			if (kipper.get_printing_amm() == 0)
				cout << "\tПечатные издания отсутствуют.\n";
			else
			{
				int num;
				cout << "\tВыбирите печатное издание. Доступны: №"
					<< (kipper.get_printing_amm() == 1 ? "" : "1 - №")
					<< (kipper.get_printing_amm() == 1 ? 1 : kipper.get_printing_amm())
					<< "\n\t->";
				cin >> num;
				try
				{
					kipper.remove_printing(num - 1);
					cout << "\tДанные успешно удалены\n";
				}
				catch (int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 6: {
			if (kipper.get_printing_amm() == 0)
				cout << "\tПечатные издания отсутствуют.\n";
			else
			{
				int num1, num2;
				cout << "\tВыбирите печатное издание. Доступны: №"
					<< (kipper.get_printing_amm() == 1 ? "" : "1 - №")
					<< (kipper.get_printing_amm() == 1 ? 1 : kipper.get_printing_amm())
					<< "\n\t->";
				cin >> num1;
				try
				{
					if (kipper.get_writer_amm(num1-1) == 0)
						cout << "\tПисатели отсутствуют.\n";
					else
					{
						cout << "\tВыбирите писателя. Доступны: №"
							<< (kipper.get_writer_amm(num1-1) == 1 ? "" : "1 - №")
							<< (kipper.get_writer_amm(num1-1) == 1 ? 1 : kipper.get_writer_amm(num1-1))
							<< "\n\t->";
						cin >> num2;
						kipper.remove_writer(num1 - 1, num2 - 1);
						cout << "\tДанные успешно удалены\n";
					}
				}
				catch (int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 7: {kipper.save_to_file("save.txt");
			cout << "\tДанные успешно сохранены\n";
			break; }
		case 0: {
			cout << "\t\t  Все несохраненные данные будут утеряны!"
				<< "\n\t\t  Продолжить?(1-Да / 0-Нет)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
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
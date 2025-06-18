#include <iostream>
#include <string>
#include "BulIst.h"
#include <regex>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	setlocale(LC_ALL, "rus");
	BulIst tab;
	tab.PrintIst();

	while (true) {
		cout << endl << "Укажите номер операции:" << endl;
		cout << " 1. Полином Жегалкина" << endl;
		cout << " 2. Найти значение по полиному Жегалкина" << endl;
		cout << " 3. СДНФ" << endl;
		cout << " 4. СКНФ" << endl;
		cout << " 5. Найти значение по БДР" << endl;
		cout << " 6. Вывести на экран таблицу истинности" << endl;
		cout << " 7. Найти значение по СДНФ" << endl;
		cout << " 0. Выход" << endl;


		char choice[5];
		cout << endl;
		cout << "   Номер: ";
		cin >> choice;
		cout << endl;
		while (true) {
			bool validInput = true;

			for (char* c = choice; *c != '\0'; ++c) {
				if (!isdigit(*c)) {
					validInput = false;
					break;
				}
			}

			if (validInput) {
				int n = atoi(choice);
				if (n >= 0 && n < 8) {
					break;
				}
			}

			std::cerr << "Некорректный ввод. Число должно быть неотрицательным и не больше 7." << endl;
			cout << "Введите число: " << endl;
			cin >> choice;
			cout << endl;
		}
		bool Out = 0;
		std::string perem;
		std::regex ZNCH("^[0-1]{4}$");
		switch (atoi(choice)) {
		case 0:
			Out = 1;
			break;
		case 1:
			tab.Print_Zhegalkin();
			break;
		case 2:
			cout << endl << "Введите значения переменных x, у, z, h в однустрочку без пробелов(пример : 0011)" << endl;
			while (true) {
				cout << endl;
				cout << "   Значение: ";
				cin >> perem;
				cout << endl;
				if (regex_match(perem, ZNCH))
					break;
				else
					cout << "Некорректный ввод, число должно содержать четыре цифры по значению равным только 0 и 1" << endl;
			}
			tab.Search_Zhegalkin(perem);
			break;
		case 3:
			tab.Print_SDNF();
			break;
		case 4:
			tab.Print_SKNF();
			break;
		case 5:
			cout << endl << "Введите четыре символа в однустрочку без пробелов (пример: 0110)" << endl;
			while (true) {
				cout << endl;
				cout << "   Значение: ";
				cin >> perem;
				cout << endl;
				if (regex_match(perem, ZNCH))
					break;
				else
					cout << "Некорректный ввод, число должно содержать четыре цифры по значению равным только 0 и 1" << endl;
			}
			tab.SearchBDR(perem);
			break;
		case 6:
			tab.PrintIst();
			break;
		case 7:
			cout << endl << "Введите значения переменных x, у, z, h в однустрочку без пробелов(пример : 1001)" << endl;
			while (true) {
				cout << endl;
				cout << "   Значение: ";
				cin >> perem;
				cout << endl;
				if (regex_match(perem, ZNCH))
					break;
				else
					cout << "Некорректный ввод, число должно содержать четыре цифры по значению равным только 0 и 1" << endl;
			}
			tab.Search_SDNF(perem);
			break;
		}
		if (Out)
			break;

	}
}
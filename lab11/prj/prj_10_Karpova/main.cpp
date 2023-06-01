#include <clocale>
#include <codecvt>
#include <locale>
#include <iostream>
#include "ModulesTkachenko.h"
#include "ModulesTitarova.h"
#include "ModulesKarpova.h"

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	wcout.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
	wcin.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
	setlocale(LC_ALL, "");

	vector<Product> products;

	read(products, "data.tsv");

	while (true) {
		int choice;

		wcout << L"Довідник кодів товарів згідно з УКТЗЕД" << endl <<
			L"1. Пошук запису" << endl <<
			L"2. Виведення бази даних на екран" << endl <<
			L"3. Зберігання довідника у заданий файл" << endl <<
			L"4. Додавання нового запису у довідник" << endl <<
			L"5. Вилучення запису із довідника" << endl <<
			L"6. Завершення роботи програми і запис даних" << endl <<
			L"Введіть необхідну дію: ";

		wcin >> choice;
		wcin.ignore();
		switch (choice) {
			case 1:
			{
				wstring record;
				wcout << L"Введіть номер запису: ";
				getline(wcin, record);
				search(products, record);
				break;
			}
			case 2:
			{
				output(products);
				break;
			}
			case 3:
			{
				wstring path;
				wcout << L"Введіть шлях до файла: ";
				getline(wcin, path);
				wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
				string converted_path = converter.to_bytes(path);
				save(products, converted_path);
				break;
			}
			case 4:
			{
				wstring section;
				wstring sectionName;
				wstring code;
				wstring name;
				wcout << L"Введіть код розділу: ";
				getline(wcin, section);
				wcout << L"Введіть назву розділу: ";
				getline(wcin, sectionName);
				wcout << L"Введіть код товару: ";
				getline(wcin, code);
				wcout << L"Введіть назву товару: ";
				getline(wcin, name);
				add(products, section, sectionName, code, name);
				break;
			}
			case 5:
			{
				wstring record;
				wcout << L"Введіть номер запису: ";
				getline(wcin, record);
				remove(products, record);
				break;
			}
			case 6:
			{
				save(products, "data.tsv");
				return 0;
			}
			default:
				wcout << L"Помилкові дані." << endl;
		}
	}
}

#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include "ModulesTitarova.h"

using namespace std;

void add(vector<Product> &vec, wstring section, wstring sectionName, wstring code, wstring name) {
	vec.push_back({});
	Product& back = vec.back();
	back.section = section;
	back.sectionName = sectionName;
	back.code = code;
	back.name = name;
}

void remove(vector<Product> &vec, wstring record) {
	bool found = false;
	for (vector<Product>::iterator it = vec.begin(); it != vec.end();) {
		if (it->code == record) {
			found = true;
			it = vec.erase(it);
		} else
			++it;
	}

	if (found)
		wcout << L"Видалено." << endl;
	else
		wcout << L"Не знайдено." << endl;
}

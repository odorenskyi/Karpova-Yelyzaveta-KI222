#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include "ModulesKarpova.h"

using namespace std;

void search(vector<Product> &vec, wstring record) {
	bool found = false;
	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec[i].code == record) {
			found = true;
			wcout << vec[i].code << L": " << vec[i].name << L", належить до розділу " << vec[i].section << L" (" << vec[i].sectionName << L")" << endl;
		}
	}
	if (!found)
		wcout << L"Не знайдено." << endl;
}

void output(vector<Product> &vec) {
    for (unsigned int i = 0; i < vec.size(); i++)
        wcout << vec[i].code << L": " << vec[i].name << L", належить до розділу " << vec[i].section << L" (" << vec[i].sectionName << L")" << endl;
}

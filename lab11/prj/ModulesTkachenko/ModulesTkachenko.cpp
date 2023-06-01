#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include "ModulesTkachenko.h"

using namespace std;

bool read(vector<Product> &vec, string file) {
	vector<vector<wstring>> content;
	vector<wstring> row;
	wstring line, word;

	wifstream data;
	data.open(file);

	data.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	if (data.is_open()) {
		while(getline(data, line)) {
			row.clear();

			wstringstream str(line);

			while(getline(str, word, L'\u0009'))
				row.push_back(word);
			content.push_back(row);
		}
	} else
		return false;

	for (unsigned int i = 0; i < content.size(); i++) {
		vec.push_back({});
		Product& back = vec.back();
		back.section = content[i][0];
		back.sectionName = content[i][1];
		back.code = content[i][2];
		back.name = content[i][3];
	}

	return true;
}

bool save(vector<Product> &vec, string file) {
	wofstream data;
	data.open(file);

	data.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	if (!data)
		return false;

	for (unsigned int i = 0; i < vec.size(); i++)
		data << vec[i].section << L'\u0009' << vec[i].sectionName << L'\u0009' << vec[i].code << L'\u0009' << vec[i].name << endl;

	return true;
}

#ifndef STRUCT_TYPE_PROJECT_1_H_INCLUDED
#define STRUCT_TYPE_PROJECT_1_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

struct Product {
	wstring section;
	wstring sectionName;
	wstring code;
	wstring name;
};

extern vector<Product> products;

#endif // STRUCT_TYPE_PROJECT_1_H_INCLUDED
